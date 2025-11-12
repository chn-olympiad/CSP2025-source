#include<bits/stdc++.h>
using namespace std;

int n,m,ans=0;
bool vis[507];
int val[507],c[27],x[27];

void dfs(int c,int *s,int num){
	if(num==n){
		int pos=0,numo=0;
		for(int i=1;i<=n;i++){
			if(val[s[i]]>=pos){
				numo++;
			}else if(!vis[i]){
				pos++;
			}else{
				pos++;
			}
		}
		if(pos==m){
			ans++;
		}
		return;
	}
	for(int i=1;i<n;i++){
		if(c&(1<<(i-1)))continue;
		int now=c|(1<<(i-1));
		s[num+1]=i;
		dfs(now,s,num+1);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>vis[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
	}
	if(n==m){
		printf("1");
	}else if(m==1){
		printf("%d",n);
	}else{
		dfs(0,x,0);
		printf("%d",ans);
	}
	return 0;
}