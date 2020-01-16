#include <iostream>
#include <vector>
#include <random>
using namespace std;

random_device rd;
default_random_engine engine(rd());


//Insures the numbers are within the accepted ranges, and prints initial line
void validateNums(int& numCount, int& maxNum) {

	if (numCount < 2)
		numCount = 2;
	if (numCount > 8)
		numCount = 8;
	if (maxNum < 6)
		maxNum = 6;
	if (maxNum > 20)
		maxNum = 20;
	cout << "Playing Mastermind with " << numCount << " numbers (1 - " << maxNum << ") \n";
}

void makeRandomSecret(vector<int>& secret, int maxNum) {
	uniform_int_distribution<int> random(1, maxNum);
	for (int i = 0; i < secret.size(); i++) {
		secret.at(i) = random(engine);
	}
}
void getSecret(vector<int>& secret, int numCount, int maxNum) {
	int number;
	int numTotal = 0;

	for (int i = 0; i < numCount; i++) {
		cin >> number;
		secret.push_back(number);
		numTotal += number;

	}
	if (numTotal != 0) {
		cout << "Using a given secret\n";
	}
	else {
		makeRandomSecret(secret, maxNum);
		cout << "Using a random secret\n";
	}
}

int main(){

	int maxNum, numCount;
	cin >> numCount;
	cin >> maxNum;
	vector<int> guess;
	vector<int> secret;

	//Insures the numbers are within the accepted ranges, and prints initial line
	validateNums(numCount, maxNum);
	
	//Gets secret
	getSecret(secret, numCount, maxNum);

}