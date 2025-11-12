#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,k;
long long ans=0;
int a,b,s=0,cnt;
int f[200005];
struct node{
	int u,v,w;
}l[2000005];
bool cmp(node q,node p){
	return q.w<p.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(x);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>l[i].u>>l[i].v>>l[i].w;
	}
	cnt=m;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=k;i++){
		cin>>s;
		for(int j=1;j<=n;j++){
			cin>>a;
			if(a==0) f[n+i]=j;
			else{
				l[++cnt].u=n+i;
				l[cnt].v=j;
				l[cnt].w=a;
			}
		}
	} 
	sort(l+1,l+cnt+1,cmp);
	s=0;
	for(int i=1;i<=cnt;i++){
		a=find(l[i].u),b=find(l[i].v);
		if(a!=b){
			ans+=l[i].w;
			f[a]=b;
			s++;
			if(s==n+k-1) break;
		}
	}
	cout<<ans<<endl;
	return 0;
} 