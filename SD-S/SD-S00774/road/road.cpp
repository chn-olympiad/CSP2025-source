#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int re(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int N=2e6+10;
struct node{
	int u,v,w;	
}a[N];
int fa[N];
int n,m,k,tot;
int c[15];
int v[15][10050];
int sum;
int newn;
int ans=0x3f3f3f3f3f3f3f3f;
inline int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
inline bool cmp(node aa,node bb){
	return aa.w<bb.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=re(),m=re(),k=re();
	for(int i=1;i<=m;i++)a[i]=(node){re(),re(),re()};
	for(int i=1;i<=k;i++){
		c[i]=re();
		for(int j=1;j<=n;j++){
			v[i][j]=re();
			a[++m]=(node){n+i,j,v[i][j]};
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int s=0;s<(1<<k);s++){
		sum=0,newn=n;
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				sum+=c[i];
				newn++;
			}
		}
		int cnt=0;
		for(int i=1;i<=m;i++){
			int fu=find(a[i].u);
			int fv=find(a[i].v);
			if(fu!=fv){
				if(a[i].u<=n||(a[i].u>n&&(s>>(a[i].u-n-1))&1)){
					fa[fu]=fv;
					cnt++;
					sum+=a[i].w;
				}
			}
			if(cnt==newn-1){
				ans=min(ans,sum);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
