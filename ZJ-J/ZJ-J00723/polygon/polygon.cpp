#include<bits/stdc++.h>
using namespace std;
int n,a[10000],t,s[10000];
long long ans;
void dfs(int r,int mx,int sn){
	while(s[mx]) mx--;
	if(sn<3) return ;
	if(r<=a[mx]*2) return ;
	ans++;
	ans%=998244353;
	for(int i=1;i<=n;i++){
		if(!s[i]){
			s[i]=1;
			dfs(r-a[i],mx,sn-1);
			s[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdin);
	cin>>n;
	int q=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) q=0;
		t+=a[i];
	}
	sort(a+1,a+n+1);
	dfs(t,n,n);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}