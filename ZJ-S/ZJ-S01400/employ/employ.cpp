#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
long long get(int x){
	long long sm=1;
	for(int i=1;i<=x;i++){
		sm=(sm*i)%998244353;
	}
	return sm;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int ss=0;
	long long sm=1;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(x==0)ss++;
	}
	if(n-ss<m){
		cout<<0;
		return 0;
	}
	sm=get(n);
	cout<<sm;
	return 0;
}