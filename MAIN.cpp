#include <iostream>
#include <cstdlib>
#include <math.h>

#define WIDTH 50
#define HEIGHT 25

#define CENTER_i WIDTH/2
#define CENTER_j HEIGHT/2

#define OUTLINE '#'
#define WAVE '0'
#define VERTICAL_BOUNDARY '|'
#define HORIZONTAL_BOUNDARY '-'
#define CENTER_BONDARY '+'

using namespace std;

double degreeToRad(double degree){
	return degree/180 * 22/7;
}

double calculateRelativeVectorAngle(int i, int j){
	double x = CENTER_i-i;
	double y = CENTER_j-j;
	return abs(atan(y/x)); // return the reference angle 
}

void draw(double AOI, double n1, double n2){
	/* 
	AOI is the angle of incidence 
	n1 is the 1st medium 
	n2 is the 2nd medium
	*/
	
	for(int j=0 ; j<HEIGHT ; j++){ // loop through the row 
		for(int i=0 ; i<WIDTH ; i++){ // loop through the column 
			//condition to draw the outline
			if(j==0 || j==HEIGHT-1) cout<<OUTLINE;
			else if(i==0 || i==WIDTH-1) cout<<OUTLINE;

			//condition to draw the boundary
			else if(i == CENTER_i && j == CENTER_j) cout<<CENTER_BONDARY;
			else if(i == CENTER_i) cout<<VERTICAL_BOUNDARY;
			

			//display the 1st medium (incidence and reflection)
			else if(i<CENTER_i){
				if(abs(calculateRelativeVectorAngle(i,j)-degreeToRad(AOI))<= 0.03491) {
					// if the error is within 0.349 rad which is 20 degree, display the result
					cout<<WAVE;
				}
				else if(j == CENTER_j) cout<<HORIZONTAL_BOUNDARY;
				else cout <<' '; 
			}

			//display the 2nd medium (refraction)
			
			else if(i>CENTER_i){
				if(j == CENTER_j) cout<<HORIZONTAL_BOUNDARY;
				else cout <<' '; 
			}
			


			//empty space
			else cout <<' ';
		}
		cout<<endl;
	}

}

void displayCalculation(double AOI,double n1,double n2){
	/*
	angle of reflection 
	T
	R
	power
	Display of formula  
	*/
	cout<<"Given Parameter: "<<endl;
	cout<<"Angle of Incidence: " <<AOI<<endl;

	cout<<"------------------------"<<endl;

	cout<<"Calculated Parameter: "<<endl;
}

int main(){
	int end_flag = 0;
	while(end_flag!=1){
		double AOI=45,n1=1,n2=1;
		cout<<"Please give the parameters: ";
		cout<<endl;
		cout<<"Angle of Incidence: ";
		cin>>AOI;

		cout<<endl;
		cout<<"n1: ";
		cin>>n1;

		cout<<endl;
		cout<<"n2: ";
		cin>>n2;
		
		draw(AOI,n1,n2);
		cout<<endl;
		displayCalculation(AOI,n1,n2);

		cout<<endl;
		cout<<"NeW GrAPh? 1 for yes, any other is no LOL";
		int temp = 0;
		cin>>temp;
		if(temp!=1) end_flag=1;

	}
	return 0;
}
