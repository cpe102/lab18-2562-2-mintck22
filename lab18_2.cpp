//Modify function overlap() form lab18_1.cpp by using pointers as input arguments.
#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *,Rect *);

int main(){
	Rect R1, R2;
	cout << "Please input Rect 1 (x y w h): ";
	cin >> R1.x >> R1.y >> R1.w >> R1.h;
	cout << "Please input Rect 2 (x y w h): ";
	cin >> R2.x >> R2.y >> R2.w >> R2.h;
	
	cout << "Overlap area = " << overlap(&R1,&R2);	
	return 0;
}

double overlap(Rect *R1,Rect *R2){
	double x1 = R1->x + R1->w;
	double y1 = R1->y - R1->h;
	double x2 = R2->x + R2->w;
	double y2 = R2->y - R2->h;
	double result, minx, maxx, miny, maxy;

	if(R1->x > R2->x){ minx = R1->x; }else{ minx = R2->x; }

	if(x1 < x2){ maxx = x1; }else{ maxx = x2; }

	if(R1->y < R2->y){ miny = R1->y; }else{ miny = R2->y; }

	if(y1 > y2){ maxy = y1; }else{ maxy = y2; }
	
	if(maxx - minx > 0 && maxy - miny < 0 ){
		result = -((maxx - minx)*(maxy - miny));
	}else{ result = 0; }

	return result;
}