#include <iostream>

using namespace std;

int main(void) {
    int n;
    int sit[20001];
    int distance = 0;
    int first = 0;

    cin>>n;
    for(int i=0; i<n; i++)
    	cin>>sit[i];


    for(int i=0; i<n; i++) {

    	if(sit[i] == 1) {
    		if(distance < ((i - first) / 2)) {
    			distance = (i - first) / 2;
    		}
    		first = i;
    	}
    }

    cout<<distance<<endl;

    return 0;
}