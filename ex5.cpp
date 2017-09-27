#include <iostream>
#include <vector> 
using namespace std;


int main()
{
	int t_steps = 100;

	struct point_data
	 {
	 	int id;
	 	vector<double> x_position;
	 	vector<double> y_position;
	 	vector<double> x_velocity;
	 	vector<double> y_velocity;
	 }point_1,point_2;

	 //initial_conditions for both point masses
	 point_1.id = 1;
	 point_1.x_position.push_back(4.);
	 point_1.y_position.push_back(2.);
	 point_1.x_velocity.push_back(1.);
	 point_1.y_velocity.push_back(-2.);

	 point_2.id = 2;
	 point_2.x_velocity.push_back(1.);
	 point_2.y_velocity.push_back(-2.);
	 point_2.x_position.push_back(3.);
	 point_2.y_position.push_back(1.);

	 
	 // Printing loop
	 for (int i = 0; i <  point_1.x_position.size(); ++i)
	 {
	 	cout << point_1.x_position[i] << endl;
	 }
	 

	return 0;
}