
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include "Job.h"

std::vector<std::string>
greedy_solve(const std::vector<Job>& jobs);

Matrix<int> dp_solve(std::vector<Job>& jobs);

int main() {
	std::ifstream ifs;
	std::string instr;
	ifs.open("jobs.txt");
	std::vector<Job> jobs;

	while (std::getline(ifs, instr)) {
		instr.erase(std::remove(instr.begin(),
			instr.end(), ' '), instr.end());
		if (instr.find('#') != std::string::npos || instr.size() == 0)
			continue;

		jobs.push_back(read_job(instr));
	}
	
	Matrix<int> solution;
	solution = dp_solve(jobs);
	for (int i = 0; i < solution.rows(); i++) {
		for (int j = 0; j < solution.cols(); j++) {
			std::cout << solution[i][j] << ",";
		}
		std::cout << std::endl;
	}
	std::vector<std::string> greedy_sol;
	greedy_sol = greedy_solve(jobs);
	auto itr = greedy_sol.begin();
	for (; itr != greedy_sol.end()-1; itr++)
		std::cout << *itr << ",";
	//skip the comma for the last item
	itr = greedy_sol.end() - 1;
	std::cout << *itr << std::endl;


}