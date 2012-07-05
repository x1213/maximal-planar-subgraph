//-----------------------------------------------------------------------------------
// A simple code that test the MPS algorighm.
//-----------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "mps.h"
using namespace std;

void find_mps(ifstream*, ofstream*);

//n nodes, with the probability of existence of each edge being p.
void random_graph_generator(int n, double p, ofstream* out) {
	(*out) << n << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if ((double)rand()/RAND_MAX <= p) (*out) << i << " " << j << endl;
		}
	}
}

//Complete graph K_n.
void complete_graph_generator(int n, ofstream* out) {
	(*out) << n << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			(*out) << i << " " << j << endl;
		}
	}
}

//-----------------------------------------------------------------------------------
// Main function.
//-----------------------------------------------------------------------------------


int main(int argc, char* argv[]) {
	if (argc == 1) {
		cout << "Usages:" << endl;
		cout << "======================" << endl;
		cout << "mps_testing -mps <infile> <outfile>" << endl;
		cout << "  Process the infile, and output the resulting maximal" << endl
			 << "  planar subgraph in the outfile." << endl;
		cout << "mps_testing -gen <infile> <outfile>" << endl;
		cout << "  Generate a random graph as the spec given in the infile." << endl;
		while (true) {
			int x = 0;
			cin >> x;
		}
	}
	ifstream in;
	in.open(argv[2]);
	ofstream out;
	out.open(argv[3]);
	if (!in.is_open() || !out.is_open()) {
		cout << "An error occurs when opening file." << endl;
		return 0;
	}
	if (argv[1][1] == 'm') find_mps(&in, &out);
	else if (argv[1][1] == 'g') {
		int n;
		double p;
		in >> n;
		in >> p;
		random_graph_generator(n, p, &out);
	}
	return 0;
}
