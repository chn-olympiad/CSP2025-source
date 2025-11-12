#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+1e2;
int n,m,k;
int fa[N],a[11][N];
int read(){
	char x;
	int f=1,sum=0;
	x=getchar();
	if(x=='-') f=-1,x=getchar();
	while(x<='9'&&x>='0'){
		sum=sum*10+x-'0';
		x=getchar();
	}
	return sum*f;
}
struct node{
	int u,v,w;
}mp[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	n=read();m=read();k=read();
	for(int i=1;i<=n+100;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int a,b,c;
		a=read();b=read();c=read();
		mp[i]={a,b,c};
	}
	for(int i=1;i<=k;i++) {
		for(int j=1;j<=n+1;j++){
			a[i][j]=read();
		}
	}
	int cnnt=m;
	if(k!=0){	
		for(int i=n+1;i<=n+k;i++){
			for(int j=2;j<=n+1;j++){
				mp[++cnnt]={i,j-1,a[i-n][j]};
			}
		}
	} 
	sort(mp+1,mp+cnnt+1,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=cnnt;i++){
		int a=mp[i].u,b=mp[i].v,c=mp[i].w;
		if(find(a)!=find(b)){
			merge(a,b);
			cnt++;
			ans+=c;
		}
		if(cnt==n+k-1){
			break;
		}
	}
	cout<<ans;
	return 0;
}
