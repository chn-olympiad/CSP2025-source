#include<bits/stdc++.h>
using namespace std;
int c[12];
int a[12][10005];
int fa[10005];
int findfa(int i){
	if(fa[i]==i)return i;
	return findfa(fa[i]);
}
int n,m,k;
bool b[12];
#define ps pair<int,pair<int,int> >
priority_queue<ps,vector<ps>,greater<ps> >chose;
priority_queue<ps,vector<ps>,greater<ps> >y;
long long Ans=0x3f3f3f3f3f3f3f3f;
void solve(int x){
	if(x==k){
		chose = y;
		for(register int i=1;i<=n;i++)fa[i]=i;
		long long t=n,ans=0;
		for(register int i=1;i<=x;i++){
			if(b[i]){
				t++;ans+=c[i];
				for(int j=1;j<=n;j++)
					chose.push(make_pair(a[i][j],make_pair(j,i+n)));
			}
		}
		int p=0;
		while(p<t-1&&!chose.empty()){
			if(ans>Ans)return ;
			int u=chose.top().second.first,v=chose.top().second.second;
			if(findfa(u)!=findfa(v))fa[findfa(u)]=findfa(v),p++,ans+=chose.top().first;
			chose.pop();
		}
		Ans=min(Ans,ans);
	//	printf("One ,ans=%lld\n",ans);
		return ;
	}
	solve(x+1);
	b[x+1]=1;
	solve(x+1);
	b[x+1]=0;
}
template<class T=int>
inline T read(){
	int a=0;char ch=getchar();
	while(ch<'0' || ch>'9')ch=getchar();
	while(ch>='0' && ch<='9')a=(a<<3)+(a<<1)+(ch^48),ch=getchar();
	return a;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(register int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		y.push(make_pair(w,make_pair(u,v)));
	}
	bool A=1;
	if(!k)A=0;
	for(register int i=1;i<=k;i++){
		c[i]=read();
		if(c[i])A=0;
		for(register int j=1;j<=n;j++){
			a[i][j]=read();
			if(a[i][j])A=0;
		}
	}
	if(A){
		puts("0");
		return 0;
	}
	solve(0);
	printf("%lld\n",Ans);	
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 5
*/
