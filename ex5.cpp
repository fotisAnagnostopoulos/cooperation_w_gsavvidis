#include <iostream>
#include <vector> 
#include <math.h> 

using namespace std;

double force(double x_01, double y_01, double x_02, double y_02);
double verlet_alg(double x_01, double y_01, double x_02, double y_02, double ux_01, double uy_01, double t));

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
double force(double x_01, double y_01, double x_02, double y_02){
	//To calculate the force we suppose that the first mass (1) is not moving antd we calculate the force that it applies to the second one
	double r = pow((pow((x_01-x_02),2.) + pow((y_01-y_02),2),0.5);
	forc = 
	return forc
}

double verlet_alg(double x_01, double y_01, double x_02, double y_02, double ux_01, double uy_01, double t){
	// This function takes as arguments the vectors (with the physical meaning) x1,x2,u1 at time t0 and returns the x-part of theposition of the particle at time t.
	// it would be useful to make this function to take the above argumenets in more compact way and return the whole vector of the new position and not only the part in the x axis.
	double a_x = force(x_02, double y_02, double x_01, double y_01);  //just the second Newton law with m  =1
	double x_new = x_01 + ux_01 * t + 1./2. * a_x * pow(t,2.);
	return x_new;

}