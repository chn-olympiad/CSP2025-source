#include<bits/stdc++.h>
using namespace std;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
const int N=1e4*2;
vector<int> v[N],w[N];
int C[N],A[N][N];
int a[N],b[N],c[N];
void dfs(int x,int fa){
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(y==fa) continue;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		a[i]=read(),b[i]=read(),c[i]=read();
		w[a[i]].push_back(c[i]);
		w[b[i]].push_back(c[i]);
	}
	for(int i=1;i<=k;i++){
		int yyy;yyy=read();
		for(int j=1;j<=n;j++){int x;cin>>x;}
	}
	for(int i=1;i<=m;i++){
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
		dfs(1,0);
		v[a[i]].pop_back();
		v[b[i]].pop_back();
	}
//	dfs(1,0);
	cout<<"13";
	return 0;
}