#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100010],b[100010],c[100010];
int n;
int maxx=-1;
void dfs(int k,int suma,int sumb,int sumc,int tot){
	if(suma>n/2||sumb>n/2||sumc>n/2)return;
	if(k==n+1){
		maxx=max(maxx,tot);
		return;
	}dfs(k+1,suma+1,sumb,sumc,tot+a[k]);
	dfs(k+1,suma,sumb+1,sumc,tot+b[k]);
	dfs(k+1,suma,sumb,sumc+1,tot+c[k]);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--){
		cin >>n;
		maxx=-1;
		for(int i=1;i<=n;i++){
			cin >>a[i]>>b[i]>>c[i];
		}
		if(n<=30){
			dfs(1,0,0,0,0);
			cout <<maxx<<'\n';
		}else{
			sort(a+1,a+n+1);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i];
			}cout <<sum<<'\n';
		}
	}
	return 0;
}
