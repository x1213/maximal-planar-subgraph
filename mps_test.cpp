//-----------------------------------------------------------------------------------
// Implementation of a MPS algorithm via PC-tree.
//-----------------------------------------------------------------------------------

#include "mps.h"

//-----------------------------------------------------------------------------------
// Finding MPS
//-----------------------------------------------------------------------------------
void find_mps(ifstream* in, ofstream* out) {
	maximal_planar_subgraph_finder m;
	m.find_mps(in, out);
}

void maximal_planar_subgraph_finder::find_mps(ifstream* in, ofstream* out) {
	read_from_file(in);
	postOrderTraversal();
	sort_adj_list();
	determine_edges();
	back_edge_traversal();
	output(out);
}

//-----------------------------------------------------------------------------------
// Imput, output
//-----------------------------------------------------------------------------------
//First line: a single integer indicates the number of nodes.
//The rest: a pair of integers (i, j) represents an edge (i, j)
//0 <= i, j < n-1, where n is number of nodes.
void maximal_planar_subgraph_finder::read_from_file(ifstream* in) {
	int node_num, n1, n2;
    //Number of nodes.
	(*in) >> node_num;
    //initialize all the nodes.
	for (int i = 0; i < node_num; ++i) {
		_node_list.push_back(new node(P_NODE));
		_node_list[i]->set_id(i);
	}
	//Set the adj-list.
	while ((*in) >> n1 >> n2) {
		_node_list[n1]->add_adj(_node_list[n2]);
		_node_list[n2]->add_adj(_node_list[n1]);
	}
}

//Output a maximal planar subgraph in the same format as input.
void maximal_planar_subgraph_finder::output(ofstream* out) {
	(*out) << _node_list.size() << endl;
	for (int i = 0; i < _edge_list.size(); ++i) {
		(*out) << _edge_list[i].first->node_id() << " " <<  _edge_list[i].second->node_id() << endl;
	}
	for (int i = 0; i < _back_edge_list.size(); ++i) {
		if (_is_back_edge_eliminate[i]) continue;
		(*out) << _back_edge_list[i].first->node_id() << " " <<  _back_edge_list[i].second->node_id() << endl;
	}
}

void maximal_planar_subgraph_finder::output_deleted_edges(ofstream* out) {
	(*out) << _node_list.size() << endl;
	for (int i = 0; i < _back_edge_list.size(); ++i) {
		if (!_is_back_edge_eliminate[i]) continue;
		(*out) << _back_edge_list[i].first->node_id() << " " <<  _back_edge_list[i].second->node_id() << endl;
	}
}
