
#include<bits/stdc++.h>
using namespace std;
inline long long _(){
	long long f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return f*x;
}
inline void __(long long x,int opt){
	int top=0;
	char st[85];
	if(x<0)putchar('-'),x=-x;
	do{
		st[++top]=x%10;x/=10;
	}while(x);
	for(int i=top;i>=1;i--)putchar(st[i]+'0');
	if(opt==0)return;
	if(opt==1)putchar(' ');
	else putchar('\n');
}
int n,m,k;
struct edge{
	int u,v;
	long long w;
}e[1000005],ee[100005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[10005];
long long c[15];
long long a[15][10005];
void init(int x){
	for(int i=1;i<=x;i++)fa[i]=i;
}
int findfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=findfa(fa[x]);
}
bool merge(int x,int y){
	x=findfa(x);y=findfa(y);
	if(x==y)return 0;
	fa[x]=y;
	return 1;
}
void _16pts(){
	init(n);
	long long ans=0;
	for(int i=1;i<=m;i++){
		int x=e[i].u,y=e[i].v;
		if(merge(x,y))ans+=e[i].w;
	}
	__(ans,2);
}
long long minn=0x3f3f3f3f3f3f3f3f;
long long mn[10005],mnid[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=_();m=_();k=_();
	for(int i=1;i<=m;i++)e[i].u=_(),e[i].v=_(),e[i].w=_();
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++){
		c[i]=_();
		for(int j=1;j<=n;j++)a[i][j]=_();
	}
	if(k==0){
		_16pts();
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		long long sum=0;
		for(int j=0;j<k;j++)if(i&(1<<j))sum+=c[j+1];
		int ncnt=0,ecnt=0;
		for(int j=1;j<=n;j++)mn[j]=0x3f3f3f3f,mnid[j]=0;
		for(int j=0;j<k;j++){
			if(i&(1<<j)){
				ncnt++;
				for(int x=1;x<=n;x++)if(a[j+1][x]<mn[x]){
					mn[x]=a[j+1][x];
					mnid[x]=ncnt+n;
				}
			}
		}
		for(int j=1;j<=n;j++)ee[++ecnt].u=mnid[j],ee[ecnt].v=j,ee[ecnt].w=mn[j];
		sort(ee+1,ee+ecnt+1,cmp);
		int ll=1,rr=1;
		int okk=n+ncnt-1,cnt=0;
		init(n+ncnt);
		while(cnt<okk){
			if(ll>m){
				if(merge(ee[rr].u,ee[rr].v))cnt++,sum+=ee[rr].w;
				rr++;
			}
			else if(rr>ecnt){
				if(merge(e[ll].u,e[ll].v))cnt++,sum+=e[ll].w;
				ll++;
			}
			else if(e[ll].w<=ee[rr].w){
				if(merge(e[ll].u,e[ll].v))cnt++,sum+=e[ll].w;
				ll++;
			}
			else{
				if(merge(ee[rr].u,ee[rr].v))cnt++,sum+=ee[rr].w;
				rr++;
			}
		}
	//	cout<<i<<' '<<sum<<endl;
		minn=min(minn,sum);
	}
	__(minn,2);
}
