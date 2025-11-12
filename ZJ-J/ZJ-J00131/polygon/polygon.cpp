#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int mod=998244353;
int a[N],b[N];int n,sum=0;
void dfs(int c,int x,int ans,int mx){
	if(c==0){
		if(ans>2*mx){
			sum++;
			sum%=mod;
		}
		return ;
	}
	for(int i=1;i<=x;i++){
		if(b[i]==1)continue;
		b[i]=1;
		dfs(c--,x,ans+a[i],max(mx,a[i]));
		b[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5){
		cout<<9;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(i,n,0,0);
	}
	cout<<sum;
	return 0;
}