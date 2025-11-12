#include<bits/stdc++.h>
using namespace std;
const int N=510;
char s[N];
int a[N];
int mark[N],b[N];
int n,m;
long long ans=0;
void dfs(int now){
	if(now>n){
		int sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				cnt++;
			}else{
				if(cnt>=a[b[i]]){
					cnt++;
				}else{
					sum++;
				}
			}
			if(sum+(n-i)<m){
				return ;
			} 
		}
		if(sum>=m){
			ans++;
		} 
		return ; 
	}
	for(int i=1;i<=n;i++)if(!mark[i]){
		b[now]=i;
		mark[i]=1;
		dfs(now+1);
		mark[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	if(n<=10){
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
