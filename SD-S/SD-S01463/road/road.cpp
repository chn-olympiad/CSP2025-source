#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=1e4+500,M=1e6+5,K=12,inf=1e18;
struct edge {
	int x,y,w;
}e[M],t[M],tr[K][N],st[K][N*K];
int fa[N];
int n,m,k;
int a[K][N],c[K];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int cnt;
int find(int x){
	return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}
edge bo[N*K];
int len[K];
void sl(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		e[i].x=read(),e[i].y=read(),e[i].w=read();
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=find(e[i].x),y=find(e[i].y);
		if(x!=y){
			fa[x]=y;
			t[++cnt]=e[i];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			tr[i][j].x=i+n;
			tr[i][j].y=j;
			tr[i][j].w=a[i][j];
		}
		sort(tr[i]+1,tr[i]+n+1,cmp);
	}
	int ans=inf;
	for(int s=0;s<(1<<k);s++){
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int po=0;
		for(int i=1;i<n;i++)st[0][i]=t[i];
		len[0]=n-1;
		int tot=0;
		for(int j=1;j<=k;j++){
			if((1<<j-1)&s){
				po+=c[j];
				++tot;
				for(int i=1;i<=n;i++){
					st[tot][i]=tr[j][i];
				}
				len[tot]=n;
			}
		}
		while(tot){
			for(int i=0;i<=tot;i+=2){
				int l=1,r=1;
				st[i][len[i]+1].w=inf;
				st[i+1][len[i+1]+1].w=inf;
				for(int j=1;j<=len[i]+len[i+1];j++){
					if(st[i][l].w<st[i+1][r].w){
						bo[j]=st[i][l];
						l++;
					}
					else {
						bo[j]=st[i+1][r];
						r++;
					}
				}
				int pq=len[i]+len[i+1];
				len[i>>1]=pq;
				for(int j=1;j<=pq;j++){
					st[i>>1][j]=bo[j];
				}
			}
			if(tot%2==0){
				len[tot/2]=len[tot];
				for(int i=1;i<=len[tot];i++)st[tot>>1][i]=st[tot][i];
			}
			tot/=2;
		}
//		sort(p+1,p+tot+1,cmp);
//		cout<<len[0]<<'\n';
		for(int i=1;i<=len[0];i++){
//			cout<<"?";
			int x=find(st[0][i].x),y=find(st[0][i].y);
			if(x!=y){
				fa[x]=y;
				po+=st[0][i].w;
			}
		}
		ans=min(ans,po);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int tt=1;
//	cin>>tt;
	while(tt--)sl();
	return 0;
}
//我真没招了 2^knklogk极限数据跑了2.5s,机房电脑3e8%*1.5s 
