#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream cin("number.in");
	ofstream cout("number.out");
	string s;
	cin>>s;
	vector<long long>a(10,0);
	for(long long i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<10){
			a[s[i]-'0']++;
		}
	}
	for(long long i=a.size()-1;i>=0;i--){
		for(long long ii=0;ii<a[i];ii++){
			cout<<i;
		}
	}
	cout<<endl;
}
