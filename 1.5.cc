#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isOneAway(string input1, string input2){
	map<char, bool> hash;
	int count = 0;

	string compare1;
	string compare2;

	if(input1.length() >= input2.length()){
		compare1 = input2;
		compare2 = input1;
	} else {
		compare1 = input1;
		compare2 = input2;
	}

	for(int i = 0; i < compare1.length(); i++){
		hash[compare1[i]] = true;
	}

	for(int i = 0; i < compare2.length(); i++){
		if(hash.count(compare2[i]) == 0){
			count++;
		}
	}

	if(count == 0 || count == 1){
		cout << count << endl;
		cout << "true" << endl;
		return true;
	} else {
		cout << count << endl;
		cout << "false" << endl;
		return false;
	}
}

int main(){
	string input1;
	string input2;

	cin >> input1;
	cin >> input2;

	isOneAway(input1, input2);
	return 0;
}
