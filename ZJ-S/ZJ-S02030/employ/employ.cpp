#include<bits/stdc++.h>
using namespace std;
long long ans=0,s;
long long a[600];
const int mod=998244353;
long long n,x,t,c[600],k,m,u,v,w,fl[20];
char cc;
long long ccc(long long a,long long b){
	int t=1,s=1;
	b=min(b,a-b);
	for(int i=1;i<=n;i++){
		t*=i;t%=mod;
		s*=(n+1-i);s%=mod;
	}return s/t;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cc;
		c[i]=int(cc)-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	long long d=1;ans=0;s=0;
	for(int i=1;i<=n;i++){
		if(d<=a[i])ans++,d++;
	}
	for(int i=m;i<=d;i++){
		s+=ccc(ans,i);
	}cout<<s%mod;
	return 0;
}

/*
4 4 0 1 2 100 2 4 100 4 3 100 1 3 100 
4 4 1 1 2 100 2 4 100 4 3 100 1 3 100 0 1 1 1 1

*/
