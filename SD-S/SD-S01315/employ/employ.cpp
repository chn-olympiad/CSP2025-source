#include<bits/stdc++.h>
using namespace std;
#define itn int

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,f=1,t=998244353;
	long long cnt=0,pw=1;
	cin>>n>>m;
	char a[n];
	int c[n];
	for(int i=0;i<n;i++){
		cin>>a[i];if(a[i]=='0') f=0;
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(f==0) cout<<0;
	else{
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=i;j++){
				pw=((pw%t)*j)%t;
			}
			cnt=(cnt+pw)%t;
		}
		cout<<cnt;
	}
	return 0;
}
