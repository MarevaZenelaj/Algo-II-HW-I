#include<iostream>
#include<string>
#include<fstream>
#include<utility> 
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;

/* Stuff left:
				- dfs
				- bfs
				- queue
				- stack
				- generate adjacent nodes function
				- write output
				- write report
*/


class State{
public:
	char **table;
	int rows, columns;
	bool visited, discovered;
	State *next;
	State *adjacencyList;
	State(char**, int m, int n);
	void print_assigned_table();
	void add_adjacent_nodes();
	bool is_within_constraints();
};

// Done
void State::print_assigned_table(){
	for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				cout << table[i][j] << '\t';
			}
		cout << endl;		
		}
}

// Done
State::State(char **tableToAdd, int m, int n){
	table = new char*[m];
	for(int i = 0; i < m; i++)
		table[i] = new char[n];

	rows = m;
	columns = n;

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++){
			table[i][j] = tableToAdd[i][j];
		}
	visited = true;
	next = NULL;
	adjacencyList = NULL;

}

// Done
bool State::is_within_constraints(){
	bool valid = true;
	// check if the rows are correct
	for(int i = 1; i < rows; i++){
		int count = 0; 
		int max = table[i][0] - '0';
		for(int j = 1; j < columns; j++){
			if(table[i][j] == 'm')
				count++;
		}
		if(count > max){
			valid = false;
			return valid;
			}
	}
	// check if the columns are correct
	for(int i = 1; i < columns; i++){
		int count = 0; 
		int max = table[0][i] - '0';
		for(int j = 1; j < rows; j++){
			if(table[j][i] == 'm')
				count++;
		}
		if(count > max){
			valid = false;
			return valid;
		}
	}

	// check if the miners are next to each other
	for(int i = 1; i<rows-1;i++){
		for(int j = 1; j < columns-1; j++){

			if(table[i][j] == 'm'){

				for(int k = i-1; k <=i+1; k++){
					for(int l = j-1; l <= j+1; l++){
						if(k != i || l != j){
							if(table[k][l] == 'm'){
								valid = false;
								return valid;					
					}
					}
				}
			}
			// big if
		}
		// outer fors
	}}

	// check if the miners are put diagonally to the mining sites
	
	for(int i = 1; i<rows;i++){
		for(int j = 1; j < columns; j++){

			if(table[i][j] == 's'){

				if(i != rows-1 || j != columns-1){

					if(i == rows - 1){
						if(table[i-1][j] == 'm' || table[i][j-1] == 'm' || table[i][j+1] == 'm'){
							if(table[i-1][j-1] == 'm' || table[i-1][j+1] == 'm'){
								valid = false;
								return valid;
							}
					}
					}

					else if(j == columns - 1){
						if(table[i-1][j] == 'm' || table[i][j-1] == 'm' || table[i+1][j] == 'm'){
							if(table[i-1][j-1] == 'm' || table[i+1][j-1] == 'm'){
								valid = false;
								return valid;
							}
						}
					}

				else{
					if(table[i-1][j] == 'm' || table[i][j-1] == 'm' || table[i][j+1] == 'm' || table[i+1][j] == 'm'){
					if(table[i-1][j-1] == 'm' || table[i-1][j+1] == 'm' || table[i+1][j-1] == 'm' || table[i+1][j+1] == 'm'){
						valid = false;
						return valid;
					}
				}
				}

			}
			else
				return valid;
			}		

		}
	}

	return valid;
}

/*
class Graph{
public:
	State *start;
	void add_node(State); 
	Graph(State start);
	void depth_first_search();
	void breadth_first_search();

};

void Graph::depth_first_search(){
	start->discovered = true;
	State currentnode = start;
	State traverse;
	State *outertraverse = start;
	while(){
		
		outertraverse->add_adjacent_nodes();
		traverse = outertraverse->adjacencyList;

	}
}

Graph::Graph(State initial){
	start = &initial;
	State *outertraverse = start;

	traverse->add_adjacent_nodes();

	while(traverse){
		traverse = outertraverse->adjacencyList;
		traverse
	}
}
*/

int main(int argc, char *argv[]){
	
	if(argc < 4){
		cout << "Not enough inputs!" << endl;
		return 0;
	}
	else{
		string input_filename = argv[2];
		string algorithm = argv[1];
		string output_filename = argv[3];

		fstream files;
		files.open(input_filename);
		if(!files.is_open()){
			cout << "There is no such file!" << endl;
			return -1;
		}
		else{
			cout << "File read successfully!" << endl;
			int rows,columns;
			files >> columns >> rows;
			int number;
			char **table;
			table = new char*[rows+1];
			for(int i = 0; i < rows+1; i++)
				table[i] = new char[columns+1];

			table[0][0] = 'x';

			for(int j = 1; j < columns+1; j++){
				files >> table[0][j];
			}
			files.ignore();
				

			for(int i = 1; i <= rows; i++){
				for(int j = 0; j <= columns; j++)
					files >> table[i][j];
				files.ignore();
			}

			State initial_node = State(table, rows+1, columns+1);
			//Graph newGraph = Graph(initial_node);
			initial_node.print_assigned_table();
			bool result = initial_node.is_within_constraints();
			cout << "Result: " << result << endl;
		}
	

	return 0;
		}
}
