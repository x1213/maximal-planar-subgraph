//-----------------------------------------------------------------------------------
// A simple code that test the MPS algorighm.
//-----------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "mps.h"
using namespace std;

void find_mps(ifstream*, ofstream*);

//n nodes, with the probability of existence of each edge being 1/p.
void random_graph_generator(int n, int p, ofstream* out) {
	(*out) << n << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (rand() % p == 0) (*out) << i << " " << j << endl;
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
	//mps <in.txt> <out.txt>
	ifstream in;
	in.open(argv[1]);
	ofstream out;
	out.open(argv[2]);
	find_mps(&in, &out);
	return 0;
}
