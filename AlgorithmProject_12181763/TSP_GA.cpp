#include "TSP_GA.h"

// 생성자(constructor)
TSP_GA::TSP_GA(const vector<vector<int>>& weight, int SP) : W(weight), shortest_path(SP), city_size(W.size()) {
	srand((unsigned int)time(NULL));
	population.reserve(POP_SIZE);
	best_fitness_individual.fitness = INF;
}

// 추가하려는 숫자가 염색체에 존재하는지 확인
bool TSP_GA::check_gnome(const vector<int>& C, int D) {
	for (int i = 0; i < C.size(); i++)
		if (C[i] == D)
			return true;
	return false;
}

// 삽입변이, IM(Insertion Mutation)
void TSP_GA::mut_gnome(vector<int>& C) {
	if (possibility() > MUTATION_RATE)
		return;

	int temp_DNA;
	while (true) {
		int from = gen_num(1, city_size - 1);
		int to = gen_num(1, city_size - 1);
		if (from != to) {
			temp_DNA = C[from];
			C.erase(C.begin() + from);
			C.insert(C.begin() + to, temp_DNA);
			break;
		}
	}
}

// 토너먼트 선택(Tournament Selection)
individual TSP_GA::select_gnome() {
	int best_fitness = INF;
	int selected = 0;

	for (int i = 0; i < TOUR_SEL_NUM; i++) {
		int select_try = gen_num(0, POP_SIZE - 1);

		if (population[select_try].fitness < best_fitness) {
			selected = select_try;

			best_fitness = population[select_try].fitness;
		}
	}

	return population[selected];
}

// 순서기반, OBX(Order-based Crossover)
void TSP_GA::cross_gnome(vector<int>& mother, vector<int>& father, vector<int>& baby1, vector<int>& baby2) {
	baby1 = mother;
	baby2 = father;

	if ((possibility() > CROSSOVER_RATE) || (mother == father))
		return;

	vector<int> positions;

	int pos = gen_num(1, city_size - 1);

	while (pos < city_size) {
		positions.push_back(pos);

		pos += gen_num(1, city_size - pos);
	}

	int dPos_m = 0, dPos_f = 0;
	for (int i = 1; i < city_size; i++) {
		for (int j : positions)
			if (baby2[i] == mother[j]) {
				baby2[i] = mother[positions[dPos_m]];
				dPos_m++;
				break;
			}
		for (int j : positions)
			if (baby1[i] == father[j]) {
				baby1[i] = father[positions[dPos_f]];
				dPos_f++;
				break;
			}
	}
}

// 염색체 생성
vector<int> TSP_GA::create_gnome() {
	vector<int> C(1, 0);
	while (true) {
		if (C.size() == city_size) {
			C.push_back(0);
			break;
		}
		int temp = gen_num(1, city_size - 1);
		if (!(check_gnome(C, temp))) {
			C.push_back(temp);
		}
	}

	return C;
}

// 처음 시작 개체군 생성
void TSP_GA::create_starting_population() {
	population.clear();

	individual temp_pop;
	while (population.size() < POP_SIZE) {
		temp_pop.gnome = create_gnome();
		temp_pop.fitness = cal_gnome_fitness(temp_pop.gnome);
		population.push_back(temp_pop);
	}

}

// 염색체 적응도 계산
int TSP_GA::cal_gnome_fitness(const vector<int>& C) {
	int temp = 0;
	for (int i = 0; i < city_size; i++) {
		if (W[C[i]][C[i + 1]] == INF) {
			temp = INF;
			break;
		}
		temp += W[C[i]][C[i + 1]];
	}

	return temp;
}

// 개체군 염색체 적응도 계산
void TSP_GA::cal_population_fitness() {
	for (int i = 0; i < POP_SIZE; i++)
		population[i].fitness = cal_gnome_fitness(population[i].gnome);
}

// 최적 적응도 설정
void TSP_GA::set_best_fitness() {
	for (int i = 0; i < population.size(); i++)
		if (best_fitness_individual.fitness > population[i].fitness)
			best_fitness_individual = population[i];
}

// 한 세대의 최단 경로의 길이와 최소 일주경로 출력
void TSP_GA::print_best() {
	cout << "세대 최단 경로의 길이: " << best_fitness_individual.fitness << '\n';
	cout << "세대 최소 일주경로: ";
	for (int i = 0; i < city_size; i++)
		cout << "V" << best_fitness_individual.gnome[i] << " -> ";
	cout << "V" << best_fitness_individual.gnome[city_size] << '\n';
}

// GA TSP
void TSP_GA::TSP_ga() {
	// Epoch
	create_starting_population();

	individual mother, father, baby1, baby2;
	vector<individual> new_population;
	new_population.reserve(POP_SIZE);
	clock_t start, end;

	int gen = 0;
	start = clock();
	while ((gen < GEN_THRES) && (best_fitness_individual.fitness != shortest_path)) {
		// Generation
		new_population.clear();
		while (new_population.size() < POP_SIZE) {
			// select parents
			mother = select_gnome();
			father = select_gnome();

			// crossover
			cross_gnome(mother.gnome, father.gnome, baby1.gnome, baby2.gnome);

			// mutation
			mut_gnome(baby1.gnome);
			mut_gnome(baby2.gnome);

			// add to new population
			new_population.push_back(baby1);
			new_population.push_back(baby2);
		}
		population = new_population;
		cal_population_fitness();
		set_best_fitness();
		end = clock();
		gen++;
	}
	cout << "<" << gen << "st Generation>\n";
	print_best();
	cout << "수행시간: " << end - start << "ms\n";
}