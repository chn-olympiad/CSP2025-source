#include<iostream>
#include<fstream>
using namespace std;
int main(){
	std::ifstream cin ("number1.in");
	std::ofstream cout ("number1.out");
	string s;
	cin>>s;
	cout<<s<<endl;
	return 0;
}

