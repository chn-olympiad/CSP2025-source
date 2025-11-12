#include<bits/stdc++.h>
using namespace std;
int n,k,a[100000],sum[100000],ans=0;
int h[100000],nxt[100000],val[100000],to[100000],tp;
void add(int u,int v,int c){
	to[++tp]=v;
	val[tp]=c;
	nxt[tp]=h[u];
	h[u]=tp;
}
int dis[100000];
queue<int>q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=a[i];
		sum[i]^=sum[i-1];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k) add(i,i+1,1);
		else add(i,i+1,0);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(int(sum[j]^sum[i-1])==k){
				add(i,j+1,1);
			}
		}
	}
	q.push(1);
	while(q.size()){
		int p=q.front();
		q.pop();
		for(int pp=h[p];pp!=0;pp=nxt[pp]){
			if(dis[p]+val[pp]>dis[to[pp]]){
				dis[to[pp]]=dis[p]+val[pp];
				q.push(to[pp]);
			}
		}
	}
	cout<<dis[n+1];
	return 0;
}
