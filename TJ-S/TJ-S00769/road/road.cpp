#include<bits/stdc++.h>
using namespace std;
const int N=10011,M=1000010;
struct A{
	int u,v,w;
}a[M+N*11];
int n,m,k,cnt,fa[N];
long long ans;
bool com[N];
int faa(int a1){
	if(fa[a1]==a1)
		return fa[a1];
	fa[a1]=faa(fa[a1]);
	return fa[a1];
}
void build(int a1,int a2){
	fa[a1]=fa[fa[a2]];
	return ;
}
bool rule(A a1,A a2){
	return a1.w<a2.w;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int j=n+1;j<=n+k;j++){
		int c,w;
		cin>>c;
		for(int i=1;i<=n;i++){
			cin>>w;
			m++;
			//cout<<m<<endl;
			a[m].u=i;
			a[m].v=j;
			a[m].w=w;
			//cout<<i<<' '<<j<<' '<<w<<endl;
		}
	}
	//cout<<endl;
//	cout<<cnt<<endl;
//	cout<<m<<endl;
	sort(a+1,a+m+1,rule);
	for(int i=1;i<=m;i++){
		if(cnt==n-1){
			//cout<<"p";
			break;
		}
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(faa(u)!=faa(v)){
			//cout<<"s";
			build(u,v);
			cnt++;
			ans+=w;
			//cout<<u<<' '<<v<<' '<<w<<'\n';
		}
	}
	//cout<<cnt<<endl;
	cout<<ans<<'\n';
	return 0;
}
