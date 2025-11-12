#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	string u,v;
} a[N];
int n,q,cnt;
bool vis[N];
string now,nxt;
inline void dfs(string x){
	if(x==nxt){
		cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		node now=a[i];
		int len=now.u.length();
		for(int j=0;j+len-1<x.length();j++){
			string nx=x;
			bool f=1;
			for(int k=0;k<len;k++){
				nx[k+j]=now.v[k];
				if(x[k+j]!=now.u[k]){
					f=0;
					break;
				}
			}
			if(f){
				vis[i]=1;
				dfs(nx);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i].u>>a[i].v;
	}
	while(q--){
		cnt=0;
		cin>>now>>nxt;
		if(now.length()!=nxt.length()){
			printf("0\n");
			continue;
		}
		dfs(now);
		printf("%d\n",cnt);
	}
	
	return 0;
}
