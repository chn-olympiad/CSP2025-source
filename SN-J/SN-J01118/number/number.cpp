#include<bits/stdc++.h>
const int N = 10^6;
using namespace std;
int main(){
	string s;
	string m;
	cin>>s;
	for(int i=0;i<=N;i++){
		if(s[i]<'a'){
			m=s[i];
			cout<<m;
		}
	}
	return 0;
} 
