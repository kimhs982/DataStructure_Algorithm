// TSP(Traveling Salesman Problem) using GA(Genetic Algorithm)
// Binary encoding, tournament selection, OBX crossover, IM mutation

#ifndef TSP_GA_H
#define TSP_GA_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "defines.h"

struct individual {
	vector<int> gnome;
	int fitness;
};

class TSP_GA {
public:
	TSP_GA(const vector<vector<int>>&, int);
	void TSP_ga();
private:
	// Variables
	const vector<vector<int>>& W;		// 유향 가중치 그래프
	const int city_size;		// 도시 개수
	int shortest_path;		// 최단 경로 길이
	vector<individual> population;		// 개체군
	individual best_fitness_individual;		// 최적 적응도 개체

	// Functions
	int gen_num(int start, int end) { return start + rand() % (end - start + 1); };		// start와 end 사이의 난수 생성
	bool check_gnome(const vector<int>&, int);		// 추가하려는 숫자가 염색체에 존재하는지 확인
	double possibility() { return double(rand()) / double(RAND_MAX + 1.0); }		// 0~1 사이의 확률 반환
	void mut_gnome(vector<int>&);		// 변이(mutation)
	individual select_gnome();		// 선택(selection)
	void cross_gnome(vector<int>&, vector<int>&, vector<int>&, vector<int>&);		// 교배(crossover)
	vector<int> create_gnome();		// 염색체 생성
	void create_starting_population();		// 처음 시작 개체군 생성
	int cal_gnome_fitness(const vector<int>&);		// 염색체 적응도 계산
	void cal_population_fitness();		// 개체군 염색체 적응도 계산
	void set_best_fitness();		// 최적 적응도 설정
	void print_best();		// 한 세대의 최단 경로의 길이와 최소 일주경로 출력
};

#endif