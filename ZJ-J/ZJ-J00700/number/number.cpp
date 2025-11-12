#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=1e9;
string s,t;
bool cmp(char a,char b){
	return a>b;
}
void solve(){
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')t+=s[i];
	}
	sort(t.begin(),t.end(),cmp);
	cout<<t;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
/*
8:40 É±T1 
²Å320pts£¬ÒªAFOÁË55555555555 
*/
