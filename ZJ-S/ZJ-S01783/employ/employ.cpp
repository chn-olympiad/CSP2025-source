#include<bits/stdc++.h>
using namespace std;
int n,m,i,ans,fl,f[510],b[510],a[510];
char s[510];
long long jc(int x){
	int i;long long S=1;
	for(i=1;i<=x;i++){
		S*=i;
		S%=998244353;
	}return S;
}
void pd(){
	int i,sum=0;
	for(i=1;i<=n;i++){
		if(s[i]=='0'||a[b[i]]<=sum){
			sum++;
		}
	}if(n-sum>=m){
		ans++;
		ans%=998244353;
	}
}
void dfs(int t){
	if(t>n){
		pd();
		return ;
	}else{
		int i;
		for(i=1;i<=n;i++){
			if(!f[i]){
				f[i]=1;
				b[t]=i;
				dfs(t+1);
				f[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s+1;
	for(i=1;i<=n;i++){
		if(s[i]!='1'){
			fl=1;
		}
	}
	for(i=1;i<=n;i++){
		cin>>a[i];
	}if(!fl){
		cout<<jc(n);
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
