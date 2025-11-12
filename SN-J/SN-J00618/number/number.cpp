#include<bits/stdc++.h>
using namespace std;
std::ifstream cin(number.in);
std::ofstream cout(number.out);
int main(){
	string s;
	cin>>s;
	long long a[10];
	memset(a,0,sizeof(a));
	for(int i=0;i<s.size();i++){
		int b;
		b=s[i]-'0';
		a[b-1]++;
	}
	for(int i=9;i>=0;--i){
		for(int j=0;j<a[i];++j){
			cout<<i+1;
		}
	}
	return 0;
}
