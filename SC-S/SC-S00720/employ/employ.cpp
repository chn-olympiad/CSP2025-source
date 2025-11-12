#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
int n,m,c[210],pl[210];
bool vis[210];
long long sum=0;
string s;
bool quanling(){
	for(int i=0;i<n-1;i++)
		if(s[i]=='1') return false;
	return true;
}
bool pd(){
	int bg=0,tg=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){
			bg++; continue;
		}
		else if(bg>=c[pl[i]]){
			bg++; continue;
		}
		tg++;
	}
	if(tg>=m) return true;
	return false;
}
void dfs(int i){
	if(i==n){
		if(pd()){
			sum++;sum%=mo;
		}
		return ;
	}
	
	for(int j=1;j<=n;j++){
		if(vis[j]) continue;
		pl[i+1]=j; vis[j]=1;
		dfs(i+1);
		pl[i+1]=0; vis[j]=0;
	}
}
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(quanling()){
		printf("0"); return 0;
	}
	dfs(0);
	printf("%lld",sum);
	return 0;
}