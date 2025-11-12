#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
vector<int> k;
signed main(){
	ifstream in("number.in");
	ofstream out("number.out");
	string s;
	in>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])) k.push_back(s[i]-'0');
	}
	sort(k.begin(),k.end());
	reverse(k.begin(),k.end());
	for(int i=0;i<k.size();i++) out<<k[i];
	return 0;
}
