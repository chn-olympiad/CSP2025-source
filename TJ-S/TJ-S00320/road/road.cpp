#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k;
int a[15][10005];
int c[15];
int vill[15];
int cntn,cnt,mn=9e18;

struct edge{
	int f,t;
	int v;
} e[1100005],ee[110005];
bool cmp(edge x,edge y){
	return x.v<y.v;
}

int s[20005];
int sz[20005];
int find(int x){
	if (x!=s[x]) s[x]=find(s[x]);
	return s[x];
}
void craft(int x,int y){
	int xx=find(x),yy=find(y);
	if (sz[xx]<sz[yy]) swap(xx,yy);
	s[yy]=xx;
	sz[xx]+=s[yy];
}
int kruskal(){
	for (int i=1;i<=cntn;i++){
		s[i]=i;
		sz[i]=1;
	}
	sort(ee+1,ee+cnt+1,cmp);
	int sum=0,cnt1=1;
	int i1=1,i2=1;
	while (i1<=m || i2<=cnt){
		int x,y,v;
		if (i1>m){
			x=ee[i2].f,y=ee[i2].t,v=ee[i2].v;
			i2++;
		}
		else if (i2>cnt){
			x=e[i1].f,y=e[i1].t,v=e[i1].v;
			i1++;
		}
		else if (e[i1].v<ee[i2].v){
			x=e[i1].f,y=e[i1].t,v=e[i1].v;
			i1++;
		}
		else{
			x=ee[i2].f,y=ee[i2].t,v=ee[i2].v;
			i2++;
		}
		int xx=find(x),yy=find(y);
		if (xx!=yy){
			craft(xx,yy);
			sum+=v;
			cnt1++;
			if (cnt1==cntn) break;
		}
		
	}
	return sum;
}
void work(){
	cntn=n;
	cnt=0;
	int sum=0;
	for (int i=1;i<=k;i++){
		if (vill[i]){
			cntn++;
			for (int j=1;j<=n;j++){
				cnt++;
				ee[cnt].f=cntn;
				ee[cnt].t=j;
				ee[cnt].v=a[i][j];
				
			}
			sum+=c[i];
		}
	}
	sum+=kruskal();
	mn=min(mn,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		e[i].f=u;
		e[i].t=v;
		e[i].v=w;
	}
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for (int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for (int i=0;i<(1<<k);i++){
		int x=i;
		for (int j=1;j<=k;j++){
			vill[j]=x%2;
			x/=2;
		}
		work();
	}
	cout<<mn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
