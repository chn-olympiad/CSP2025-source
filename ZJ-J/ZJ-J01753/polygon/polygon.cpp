#include<bits/stdc++.h>
using namespace std;
int a[5005],ans=0,n,m=998244353;
bool st[5005];
void dfs(int x,int d,int mx,int xb){
	if(d>mx*2&&x>=3){
		ans=(ans+1)%m;
	}
	for(int i=xb+1;i<=n;i++){
		if(st[i]==0){
			st[i]=1;
			dfs(x+1,d+a[i],max(mx,a[i]),i);
			st[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	if(flag==0){
		int w=0;
		for(int i=1;i<=n-2;i++){
			w=(w+i)%m;
		}
		cout<<w%m;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans%m;
	return 0;
}

