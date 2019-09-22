#include <iostream>

using namespace std;

int ways(int n, int k) 
{ 
	if (k==0 || k==n) 
		return 1; 

	return  ways(n-1, k-1) + ways(n-1, k); 
} 

int main(void) {
	int x, y;
	int cx, cy;
	int time;

	cin>>x>>y;
	cin>>cx>>cy;

	if(cx > x || cy > y || cx < 0 || cy < 0) {
		cout<<"fail"<<endl;
		return 0;
	}

	time = cx + cy;

	cout<<time<<endl;
	cout<<ways(cx+cy, cy)<<endl;


	return 0;
}