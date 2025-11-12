#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10,mod=998244353;
int n,s,a[N],maxn,sum;
void dfs(int id,int x,int ma,int s){
	if(x>=3)
		if(s>ma*2) sum++;
	if(id==n) return ;
	for(int i=id+1;i<=n;i++)
		dfs(i,x+1,max(ma,a[i]),s+a[i]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) s++;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		s=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
			s+=a[i];
		}
		if(s>maxn*2) cout<<1;
		else cout<<0;
		return 0;
	}
	if(s==n){
		ll sum=0;
		for(int i=3;i<=n;i++){
			ll f=1;
			for(int j=n;j>=n-i+1;j--)
				f=(f*j)%mod;
			for(int j=1;j<=i;j++)
				f=f/j;
			sum=(sum+f)%mod;
		}
		cout<<sum;
		return 0;
	}
	if(n<=20){
		dfs(0,0,0,0);
		cout<<sum;
		return 0;
	}
	return 0;
}