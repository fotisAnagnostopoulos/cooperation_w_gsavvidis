#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector> 
#include <cmath> 

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int N = 100000;
	int node_num[100000] = {0};
	double gamma = 2.;
	int i = 0,j = 0;
	//we need to create all the possible pairs of nodes
	//So we calculate the number
	while(i<N){
		j = 0;
		while (j<N){
			int cond;
			// if (node_num[i] == 0){
			// 	cond = (rand()%6);
			// }
			// else{
				cond = (rand()%int(pow(node_num[i]+1,gamma)));
			// }
			 
			if (cond  == 0){
				node_num[i] = node_num[i] + 1.;
				//node_num[i] = (rand()%10);
			}
			j++;
			//node_num[i] = rand() / (RAND_MAX + 1.);
		}
		//afairw thn tautotikh (i,i) syndesh
		node_num[i] = node_num[i] -1 ;
		i++;
	}
	
	ofstream myfile;

	 // Printing loop
	 myfile.open ("data3b.txt");
	for (int i = 0; i < N; ++i)
	{
		//cout << i << "os kombos: " << node_num[i] << " syndesmoi" << endl;
		myfile << i << "," << node_num[i] << endl;
	}
	myfile.close();
	return 0;
}
