#include <bits/stdc++.h>
using namespace std;
int n,k,i,x,ans,flag,f[50000],a[200010],e[200010];
void solve(){
	int i,t,w,ans=0,j;
	for(i=1;i<=n;i++)
		for(t=1;t<=n-i+1;t++){
			w=t+i-1;
			for(j=t;j<=w;j++)
				if(e[j]==1) break;
			if(j>w){
				int zh=0;
				for(j=t;j<=w;j++) zh=zh^a[j];
				if(zh!=k) continue;
				for(j=t;j<=w;j++) e[j]=1;
				ans++;
			}
		}
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flag=1;
		f[a[i]]++;
	}
	if(flag==1){
		solve();
		return 0;
	}
	if(k==1){
		cout<<f[1];
		return 0;
	}
	for(i=1;i<=n;i++)
		if(a[i]==0) ans++;
		else if(a[i]==1&&a[i-1]==1) ans++,a[i]=0;
	cout<<ans;
	return 0;
}
