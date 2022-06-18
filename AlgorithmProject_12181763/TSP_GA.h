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
	const vector<vector<int>>& W;		// ���� ����ġ �׷���
	const int city_size;		// ���� ����
	int shortest_path;		// �ִ� ��� ����
	vector<individual> population;		// ��ü��
	individual best_fitness_individual;		// ���� ������ ��ü

	// Functions
	int gen_num(int start, int end) { return start + rand() % (end - start + 1); };		// start�� end ������ ���� ����
	bool check_gnome(const vector<int>&, int);		// �߰��Ϸ��� ���ڰ� ����ü�� �����ϴ��� Ȯ��
	double possibility() { return double(rand()) / double(RAND_MAX + 1.0); }		// 0~1 ������ Ȯ�� ��ȯ
	void mut_gnome(vector<int>&);		// ����(mutation)
	individual select_gnome();		// ����(selection)
	void cross_gnome(vector<int>&, vector<int>&, vector<int>&, vector<int>&);		// ����(crossover)
	vector<int> create_gnome();		// ����ü ����
	void create_starting_population();		// ó�� ���� ��ü�� ����
	int cal_gnome_fitness(const vector<int>&);		// ����ü ������ ���
	void cal_population_fitness();		// ��ü�� ����ü ������ ���
	void set_best_fitness();		// ���� ������ ����
	void print_best();		// �� ������ �ִ� ����� ���̿� �ּ� ���ְ�� ���
};

#endif