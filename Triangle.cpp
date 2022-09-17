//Programme c++ qui verifie la nature de triangle
#include <iostream>// allows program to perform input and output
#include <cmath>//standard library to perform mathematical operations
using namespace std;// program uses names from the std namespace

//Point class defintion
//class pour les trois points de triangle
class Point
{
	public:
	//// constructor initializes namePoint, x et y
		explicit Point(char name, int xx, int yy)
			:namePoint(name), x(xx), y(yy)// member initializer to initialize namePoint, x et y
		{
		}// end constructor
		
		// function to set the namePoint coordinated
		void setNamePoint(char name)
		{
			namePoint=name;// store the point name in the object
		}
		
		// function to set the x coordinated
		void setX(int n)
		{
			x=n;
		}
		
		// function to set the y coordinated
		void setY(int n)
		{
			y=n;
		}
		
		// function that gets the name of a point
		char getNamePoint()
		{
			return namePoint;
		}
		
		// function that gets the x coordinated
		int getX()
		{
			return x;
		}
		
		// function that gets the y coordinated
		int getY()
		{
			return y;
		}
		
		// function that displays the coordinates of a point
		void displayMsg()
		{
			cout<<getNamePoint()<<"("<<getX()<<","<<getY()<<")";
		}
		
	//private Members
	private:
		char namePoint;
		int x;
		int y;
};//end class Point

//segment class defintion
//class pour calculer la langueur des trois segments de triangle
class Segment
{
	public:
		// constructor initializes deux points
		explicit Segment(Point m, Point j)
			:p1(m), p2(j)// member initializer to initialize deux points
		{
		} // end constructor
		
		// function to set the first point
		void setP1(Point m)
		{
			p1=m;
		}
		
		// function that gets the first point
		Point getP1()
		{
			return p1;
		}
		
		// function to set the second point
		void setP2(Point j)
		{
			p2=j;
		}
		
		// function that gets a second point
		Point getP2()
		{
			return p2;
		}
		
		//fonction retourne la distance d'un segment
		float distSegment()
		{
			float x,y,dist;
			x=p1.getX()-p2.getX();
			y=p1.getY()-p2.getY();
			dist=sqrt(pow(x,2)+pow(y,2));
			return dist;
		}
		
		//fonction pour regler l'erreur du resultat float de fonction distSegment()
		bool reglErreur (float dist)
		{	
	     	return abs((distSegment()*distSegment())-dist)<=0.0001;
		}
	
		//fonction qui affiche la distance du segment
		void displayMsg()
		{
			cout<<"\ndistance entre ";
			p1.displayMsg();
			cout<<" et ";
			getP2().displayMsg();
			cout<<" egale "<<distSegment();
		}
		
	//private members
	private:
		Point p1;
		Point p2; 
};//end class Segment

//triangle class defintion
//class de nature de triangle
class Triangle
{
	public:
		// constructor initializes trois points
		explicit Triangle (Point a, Point b, Point  c)
			:p1(a), p2(b), p3(c)// member initializer to initialize trois points
		{
		}// end constructor
		
		// function to set the first point
		void setP1(Point  a)
		{
			p1=a;
		}
		
		// function that gets the first point
		Point getP1()
		{
			return p1;
		}
		
		// function to set the second point
		void setP2(Point b)
		{
			p2=b;
		}
		
		// function that gets the second point
		Point getP2()
		{
			return p2;
		}
		
		// function to set the third point
		void setP3(Point c)
		{
			p3=c;
		}
		
		// function that gets the third point
		Point getP3()
		{
			return p3;
		}
		
	    //fonction qui test si un triangle est isocele retourne 1,2 ou 3 si oui et 0 si non
		int estIsocele()
		{
			Segment s1(p1,p2);
			Segment s2(p1,p3);
			Segment s3(p2,p3);
			//check condition
			if(s1.distSegment()==s2.distSegment())//segment s1 egale segment s2
			{
				return 1;
	    	}
	    	else if (s2.distSegment()==s3.distSegment())//segment s3 egale segment s2
	    	{
	    		return 2;
			}
			else if(s1.distSegment()==s3.distSegment())//segment s1 egale segment s3
			{
				return 3;
			}
			else
	    	{
	    		return 0;
	    	}
	    }
	     
	     // fonction qui test si un triangle est rectangle retourne 1, 2 ou 3 si oui et 0 si non
	    int estRectangle()
	    {
	     	Segment s1(p1,p2);
			Segment s2(p1,p3);
			Segment s3(p2,p3);
			//raising base to the power exponent
			float ds12=pow(s1.distSegment(),2);
			float ds22=pow(s2.distSegment(),2);
			float ds32=pow(s3.distSegment(),2);
			//check condition
			if((s1.reglErreur(ds22+ds32)==1))
			{
				return 1;
			}
			else if ((s2.reglErreur(ds12+ds32))==1)
			{
				return 2;
			}
			else if ((s3.reglErreur(ds22+ds12))==1)
			{
				return 3;
			}
			else
			{
				return 0;
			}
	    }
	     
	     // fonction qui test si un triangle est equilateral retourne 1 si oui et 0 si non
	    int estEquilateral()
	    {
	     	Segment s1(p1,p2);
			Segment s2(p1,p3);
			Segment s3(p2,p3);
			//check condition
			if((s1.distSegment()==s2.distSegment())&&(s1.distSegment()==s3.distSegment()))
			{
			    return 1;
			}
			else
			{
				return 0;
			}
		}
		
		 //function that display the nature of the triangle
		 void displayMsg()
		 {
		 	Segment s1(p1,p2);
			Segment s2(p1,p3);
			Segment s3(p2,p3);
			//check condition
			//isocele triangle
			if (estIsocele()==1)
		 	{
		 		cout<<"\n >>isocele";
		 		s1.displayMsg();
		 		cout<<" egale à  ";
		 		s2.displayMsg();
		 		cout<<endl;
			}
			else if (estIsocele()==2)
			{
				cout<<"\n >>isocele";
		 		s3.displayMsg();
		 		cout<<" egale à  ";
		 		s2.displayMsg();
		 		cout<<endl;
			}
			else if (estIsocele()==3)
			{
				cout<<"\n >>isocele";
		 		s1.displayMsg();
		 		cout<<" egale à  ";
		 		s3.displayMsg();
		 		cout<<endl;
			}
			//triangle rectangle
			if(estRectangle()==1)
			{
				cout<<"\n >>rectangle en ";
				p3.displayMsg();
				cout<<endl;
			}
			else if(estRectangle()==2)
			{
				cout<<"\n >>rectangle en ";
				p2.displayMsg();
				cout<<endl;
			}
			else if(estRectangle()==3)
			{
				cout<<"\n >>rectangle en ";
				p1.displayMsg();
				cout<<endl;
			}
			//triangle equilateral
			if(estEquilateral()==1)
			{
				cout<<"\n >>equilateral: les trois segment sont egaux\n ";
			}
			//triangle quelconque
			if((estEquilateral()==0)&&(estRectangle()==0)&&(estIsocele()==0))
			{
				cout<<"\n>>triangle quelconque\n";
			}
		 }
		 
		//private members
		private:
			Point p1;
			Point p2;
			Point p3;
};//end class Triangle

// function main begins program execution
int main()
{
	//creat a point objects
	Point A('A',0,1);
	Point B('B',1,0);
	Point C('C',1,0);	
	//creat a Segment objects
	Segment AB(A,B);
	Segment BC(B,C);
	Segment AC(A,C);

	cout<<"les trois point de triangle sont: "<<endl;// afficher un message
	//appel au fonction displayMsg de class Point pour afficher les points
	A.displayMsg();
	cout<<endl;//retour a la ligne
	B.displayMsg();
	cout<<endl;
	C.displayMsg();
	cout<<endl;
	//appel au fonction displayMsg de class Segment pour afficher la longueur de trois segments de triangle
	AB.displayMsg();
	BC.displayMsg();
	AC.displayMsg();
	cout<<endl;
	//creat a triangle object named T
	Triangle T(A,B,C); 
	//affichage de nature de triangle a partir de class triangle
	cout<<"\nc'est un triangle: ";
	T.displayMsg();	
	return 0;
}//end main
