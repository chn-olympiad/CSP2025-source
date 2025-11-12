#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
string s;
int n,m;
int f[510],t[510];
void solve1(){
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>f[i];
	for(int i=1;i<=n;i++)
		t[i]=i;
	int ans=0;
	do{
		int cnt=0,cor=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){cnt++;continue;}
			if(cnt>=f[t[i]]){cnt++;continue;}
			cor++;
		}
		if(cor>=m)ans++;
	}while(next_permutation(t+1,t+1+n));
	cout<<ans;
}
void solve2(){
	cin>>s;int sw=0;
	for(int i=1;i<=n;i++){
		cin>>f[i];if(f[i])sw++;}
	int st=1;
	for(int i=sw;i>=1;i--)
		st*=i,st%=mod;
	cout<<st;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n<=10)solve1();
	else solve2();
	return 0;
}
