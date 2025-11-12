#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10,inf=-0x3F3F3F3F;
queue <int> q;
int n,m,c[N];
int s,ans=0,cnt=0;
int vis[N]

int main(){
	//freopen("employ1.in","r",stdin);
	//freopen("employ1.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[1]);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		cnt=1;
		q.push(i);
		vis[i]=1;
		js();
	}
	return 0;
}