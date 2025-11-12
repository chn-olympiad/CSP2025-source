#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int t[15];
char a;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		a=s[i];
		if(a>='0'&&a<='9'){
			t[a-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(t[i]==0) continue;
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
