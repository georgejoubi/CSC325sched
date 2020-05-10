#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include "Job.h"
using namespace std;

std::vector<std::string> greedy_solve(const std::vector<Job>& jobs) {

	priority_queue<Job> sortedJobs; //uses overloaded operator<
	int max = 0;
	while (!jobs.empty()) {
		//order jobs by max profit and find max deadline
		sortedJobs.push(jobs.back());
		if (jobs.back().deadline() > max) {
			max = jobs.back().deadline();
		}
		jobs.pop_back();
	}

	vector<string> solution;
	bool timeSlots[max];

	for (int i = 0; i<max; i++) {
		timeSlots[i] = false;
	}

	while (!sortedJobs.empty()) {
		for (int i = min(max, sortedJobs.top().deadline()) - 1; i >= 0; i--) {
			if (timeSlots[i-1] == false) {
				solution.push_back(sortedJobs.top().name());
				timeSlots[i-1] = true;
				break;
			}
		}
		sortedJobs.pop();
	}

	solution.shrink_to_fit();
	return solution;

}


Matrix<int> dp_solve(std::vector<Job>& jobs) {

	int n = jobs.size();
	int max = 0;

	for (int i = 0; i <= n; i++) {
		if (jobs[i].deadline() > max) {
			max = jobs[i].deadline();
		}
	}

	Matrix<int> T(n + 1, max + 1);

	for (int i = 0; i <= n; i++) {
		T[i][0] = 0;
	}
	for (int i = 0; i <= max; i++) {
		T[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= max; j++) {

			jobs[i - 1].setStart(std::min(j, jobs[i - 1].deadline()) - jobs[i - 1].duration());

			if (jobs[i - 1].start() < 0) {
				T[i][j] = T[i - 1][j];
			} else {
				T[i][j] = std::max(T[i - 1][j], jobs[i - 1].profit() + T[i - 1][jobs[i - 1].start()]);
			}

		}
	}

	return T;

}

std::vector<string> dp_solution(Matrix<int> T, std::vector<Job>& jobs) {

	std::vector<string> solution;
	
	int i = T.rows();
	int j = T.cols();

	while (i != 0) {
		if (T[i][j] == T[i - 1][j]) {
			i--;
		} else {
			j = std::min(j, jobs[i - 1].deadline()) - jobs[i - 1].duration();
			solution.insert(solution.begin(), jobs[--i].name());
		}
	}

	return solution;

}

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
