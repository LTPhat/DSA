#include <iostream> 
#include <vector> 
using namespace std;

int main(){
    const int r = 3;
    const int c = 5;
    vector<vector<int>> grid; 
	for(int i=0;i<r;++i) { 
		//Create a vector  
		vector<int> row; 
		for(int j=0;j<c;++j){ 
			int value; 
			cin >> value; 
			row.push_back(value); 
		} 
		//Push the row in matrix 
		grid.push_back(row); 
	}
    for(int i=0;i<r;++i) { 
		for(int j=0;j<c;++j){ 
			std::cout << grid[i][j] << " "; 
		} 
		std::cout << "\n"; 
	} 
    return 0;
}
