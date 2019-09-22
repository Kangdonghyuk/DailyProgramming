#include <iostream>

using namespace std;

int msg;
int consumer;
int msgCount;
int msglist[10];
int consumerlist[10];
int sec = 0;


void second() {
	int st = 0;
	for(int i=0; i<consumer; i++) {
		if(consumerlist[i] > 0)
			st = 1;
	}
	if(st == 0)
		return ;

	for(int i=0; i<consumer; i++) {
		consumerlist[i] -= 1;
		if(consumerlist[i] <= 0 && msgCount < msg)
			consumerlist[i] = msglist[msgCount++];
	}

	sec += 1;

	second();
}

int main(void) {

	cin >> msg >> consumer;
	msgCount = 0;


	for(int i=0; i<msg; i++)
		cin>>msglist[i];

	for(int i=0; i<consumer; i++) {
		consumerlist[i] = 0;
		consumerlist[i] = msglist[msgCount++];
	}
	
	second();

	cout<<sec<<endl;


	return 0;
}

