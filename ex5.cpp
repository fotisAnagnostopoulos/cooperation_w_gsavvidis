#include <iostream>
#include <fstream>
#include <vector> 
#include <math.h> 

using namespace std;

double force(double x_01, double y_01, double x_02, double y_02);
double verlet_alg(double x_01, double y_01, double x_02, double y_02, double ux_02, double t);
double velocity_verlet(double ux_01, double force_old,double force_new, double t);

int main()
{
	int t_steps = 50;
	double t = 1.;
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
	 point_1.x_position.push_back(4.); //4.  is the correct value
	 point_1.y_position.push_back(2.); //2.
	 point_1.x_velocity.push_back(1.);
	 point_1.y_velocity.push_back(-2.);

	 point_2.id = 2;
	 point_2.x_velocity.push_back(1.);
	 point_2.y_velocity.push_back(-2.);
	 point_2.x_position.push_back(3.); //3
	 point_2.y_position.push_back(1.);//1

	 //calculating loop
	 double dt = t/t_steps;
	 double t_tot = 0.;
	 for (int i = 0; i < t_steps; ++i)
	 {	
	 	//useful (for better readability) variables
	 	double x_01 = point_1.x_position[i];
	 	double y_01 = point_1.y_position[i];

	 	double ux_01 = point_1.x_velocity[i];
	 	double uy_01 = point_1.y_velocity[i];

	 	double x_02 = point_2.x_position[i];
	 	double y_02 = point_2.y_position[i];

	 	double ux_02 = point_2.x_velocity[i];
	 	double uy_02 = point_2.y_velocity[i];

	 	double force_old_12_x = force(x_01,y_01,x_02,y_02);
	 	double force_old_12_y = force(y_01,x_01,y_02,x_02);
	 	double force_old_21_x = force(x_02,y_02,x_01,y_01);
	 	double force_old_21_y = force(y_02,x_02,y_01,x_01);

	 	//Initially the first point mass stays at rest and the second one moves. Its new position:
	 	double x_2new = verlet_alg(x_01, y_01, x_02, y_02, ux_02, dt);
	 	point_2.x_position.push_back(x_2new);
	 	//for both coordinates (just interchanging x <--> y):
	 	double y_2new = verlet_alg(y_01, x_01, y_02, x_02, uy_02, dt);
	 	point_2.y_position.push_back(y_2new);


	 	//Secondly, the poin mass with id = 2 stays at rest and the first one moves, so we have to set x_01 --> x_02 and also y_01 --> y_02
	 	double x_1new = verlet_alg(x_02, y_02, x_01, y_01, ux_01, dt);
	 	point_1.x_position.push_back(x_1new);
	 	////Similar to the above
	 	double y_1new = verlet_alg(y_02, x_02, y_01, x_01, uy_01, dt);
	 	point_1.y_position.push_back(y_1new);
	 	/////

	 	double force_new_12_x = force(x_1new,y_1new,x_2new,y_2new);
	 	double force_new_12_y = force(y_1new,x_1new,y_2new,x_2new);
	 	double force_new_21_x = force(x_2new, y_2new, x_1new,y_1new);
	 	double force_new_21_y = force(y_2new,x_2new,y_1new,x_1new);

	 	//Now, the velocities 
	 	double ux_2new = velocity_verlet(ux_02,force_old_12_x,force_new_12_x,dt);
	 	point_2.x_velocity.push_back(ux_2new);
	 	//similar with the displacement (i hope)
	 	double uy_2new = velocity_verlet(uy_02,force_old_12_y,force_new_12_y,dt);
	 	point_2.y_velocity.push_back(uy_2new);

	 	double ux_1new = velocity_verlet(ux_01,force_old_21_x,force_new_21_x,dt);
	 	point_1.x_velocity.push_back(ux_1new);
	 	//similar with the displacement (i hope)
	 	double uy_1new =  velocity_verlet(uy_01,force_old_21_y,force_new_21_y,dt);
	 	point_2.y_velocity.push_back(uy_1new);

	 	///All these additional variables are not needed but it is more readable that way. This must be reconsidered.
	 }

	  ofstream myfile;

	 // Printing loop
	 myfile.open ("data1.txt");
	 for (int i = 0; i <  point_1.x_position.size(); ++i)
	 {
	 	t_tot += dt;
	 	// cout << point_1.x_position[i] <<"," << endl;
	 	// cout << pow(pow(point_1.x_position[i],2.) + pow(point_1.y_position[i],2.),0.5) <<"," << endl;
	 	//cout << pow(pow(point_2.y_position[i]-point_1.y_position[i],2.) + pow(point_2.x_position[i]-point_1.x_position[i],2.),0.5) <<"," << endl;
	 	
  		myfile << sqrt(pow(point_2.y_position[i]-point_1.y_position[i],2.) + pow(point_2.x_position[i]-point_1.x_position[i],2.)) <<"\t";
  		myfile << sqrt(pow(point_1.x_position[i],2.) + pow(point_1.y_position[i],2.)) <<"\t";
  		myfile << sqrt(pow(point_2.x_position[i],2.) + pow(point_2.y_position[i],2.)) <<"\t";
  		myfile << sqrt(pow(point_1.x_velocity[i],2.) + pow(point_1.y_velocity[i],2.)) <<"\t";
  		myfile << sqrt(pow(point_2.x_velocity[i],2.) + pow(point_2.y_velocity[i],2.)) <<"\t";
  		myfile << point_1.x_position[i] << "\t";
  		myfile << point_1.y_position[i] << "\t";
  		myfile << point_2.x_position[i] << "\t";
  		myfile << point_2.y_position[i] << "\t";
  		myfile << t_tot <<endl;
	 }
	 myfile.close();



	return 0;
}
double force(double x_01, double y_01, double x_02, double y_02){
	//To calculate the force we suppose that the first mass (1) is not moving and works as a source of the field.
	double r = pow(pow((x_01-x_02),2.) + pow((y_01-y_02),2),0.5);
	double forc = 12.*(x_01-x_02)/pow(r,14.)-6.*(x_01-x_02)/pow(r,8.);
	return forc;
}

double verlet_alg(double x_01, double y_01, double x_02, double y_02, double ux_02, double t){
	// This function takes as arguments the vectors (with the physical meaning) x1,x2,u1 at time t and returns the x-part of theposition of the particle at time t+dt.
	// in order to calculate the y-part of displacement, we just need to interchange x with y. This is only true for the lenard - jones potential due to spatial symetry. (see the python notebook
	//for the proof)
	// In order to calculate the force from 2 to 1 particle, we just need to intechange point_1 elements with those of point_2. The whole function needs to be reconsidered.
	double a_x = force(x_01, y_01, x_02, y_02);  //just the second Newton law with m  =1, the acceleration of the second point mass due to the first one
	double x_new = x_02 + ux_02 * t + 1./2. * a_x * pow(t,2.);
	return x_new;

}

double velocity_verlet(double ux_02, double force_old,double force_new, double t){
	double vel;
	vel = ux_02 + ((force_old + force_new)/2.) * t;

	return vel;
}
