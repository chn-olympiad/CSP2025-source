#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5010],la,ans=0;
void dfs(int k,int op,int maxn,int cnt){
	if(op>la){
		return;
	}
	if(op==la){
		if(cnt>maxn*2){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=k+1;i<=n;i++){
		dfs(i,op+1,max(maxn,a[i]),cnt+a[i]);		
	}
}
int main(){
	//SN-J00657 Lianglinyi TYQJ
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		la=i;
		dfs(0,0,0,0);
	}
	cout<<ans;	
	return 0;
}
