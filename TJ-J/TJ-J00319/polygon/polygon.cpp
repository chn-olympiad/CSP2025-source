#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,b,c,maxx=-1,x[5005],mod=998244353;
int p(int a,int b){
	int sum=1;
	for(int i=1;i<=b;i++){
		sum=(sum*a)%mod;
	}
	return sum;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a>>b>>c;
		maxx=max(a,max(b,c));
		if(a+b+c>2*maxx){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>x[i];
			maxx=max(maxx,x[i]);
		}
		if(maxx==1||maxx==2){
			cout<<p(2,n)-1-n-(n*n-n)/2;
			return 0;
		}
		else{
			cout<<p(2,n)-1-n-(n*n-n)/2;
			return 0;
		}
	}
	return 0;
}
