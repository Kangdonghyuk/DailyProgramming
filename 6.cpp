#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int sum(int n) {
	int result = 1;

	while(n > 1) {
		result *= n;
		n-=1;
	}

	return result;
}

int main(void) {
    int num[10];
    int result[10];
    int in = 0;
    int index = 0;
    int count = 0;
    char inp[20];

    vector<int> arr;

    gets(inp);
    cin>>count;
    count = count - 1;

    for(int i=0; inp[i] != '\0'; i++) {
    	if(inp[i] != ' ') {
    		arr.push_back(inp[i] - '0');
    		index+=1;
    	}
    }

    sort(arr.begin(), arr.end());

    while(!arr.empty()) {
    	index = count / sum(arr.size()-1);
    	count = count % sum(arr.size()-1);
    	result[in++] = arr[index];
    	arr.erase(arr.begin() + index);
    }

    for(int i=0; i<in; i++)
    	cout<<result[i];

    return 0;
}