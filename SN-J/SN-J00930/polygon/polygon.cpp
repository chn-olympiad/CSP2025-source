#include<bits/stdc++.h>
using namespace std;
int n,a[5050],ans;
const int mod=998244353;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int o,int c){
	for(int i=o+1;i<=n;i++){
		if(a[i]>c)ans++;
		ans%=mod;
		dfs(i,c-a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		dfs(i,a[i]);
	}
	cout<<ans%mod;
	return 0;
}
//GOOD!Ð´ÍêÁË£¡ 
