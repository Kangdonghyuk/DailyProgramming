#include <iostream>
#include <string.h>

using namespace std;

int main(void) {
    int num;
    char type[10];
    int types[100];
    int col, row;
    int maxSize = 3;
    char numbers[100][1000];

    cin>>num;
    cin>>type;

    for(int i=0; i<num; i++) {
    	cin>>types[i];
    	char a = getchar();
    	cin>>numbers[i];
    	if(types[i] > maxSize)
    		maxSize = types[i];
    }

    cout<<numbers[0]<<endl;

    return 0;
}