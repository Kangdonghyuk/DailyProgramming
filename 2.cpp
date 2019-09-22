#include <iostream>

using namespace std;

int main(void) {
    int n;
    int io[2000][2];
    int toilet[150];
    int count = 0;

    cin>>n;

    for(int i=0; i<150; i++)
    	toilet[i] = 0;
    for(int i=0; i<n; i++)
    	cin>>io[i][0]>>io[i][1];

    for(int i=0; i<n; i++) {
    	for(int j=io[i][0]; j<io[i][1]; j++)
    		toilet[j] += 1;
    }


    for(int i=0; i<150; i++) {
    	if(count < toilet[i])
    		count = toilet[i];
    }

    cout<<count;

    return 0;
}