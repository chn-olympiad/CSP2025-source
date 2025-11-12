#include<bits/stdc++.h>
#define int long long
using namespace std;
struct no{
	int x,y,w;
}a[2000010];
struct node{
	int x,y,w,id;
}b[1000010];
int n,m,k,i,fx,fy,cnt,s,j,f[100010],c[100010],x,ans,sum,ss,pd[100010];
bool cmp(no t,no w){
	return t.w<w.w;
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool cmp2(node t,node w){
	return t.w<w.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].w;
	for(i=1;i<=n;i++)f[i]=i;
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=m;i++){
		fx=find(a[i].x);
		fy=find(a[i].y);
		if(fx!=fy){
			f[fx]=fy;
			b[++cnt].id=0;
			b[cnt].x=a[i].x;
			b[cnt].y=a[i].y;
			b[cnt].w=a[i].w;
		}
	}
	for(i=n+1;i<=n+k;i++){
		cin>>c[i];
		for(j=1;j<=n;j++){
			cin>>x;
			b[++cnt].id=i;
			b[cnt].x=i;
			b[cnt].y=j;
			b[cnt].w=x;
		}
	}
	sort(b+1,b+1+cnt,cmp2);
	pd[0]=1;ans=1e14;
	for(i=0;i<(1<<k);i++){
		for(j=n+1;j<=n+k;j++)pd[j]=0;
		sum=0;s=0;
		for(j=1;j<=k;j++)
			if((i>>(j-1))&1)pd[n+j]=1,sum+=c[n+j],s++;
		for(j=1;j<=n+k;j++)f[j]=j;
		ss=0;
		for(j=1;j<=cnt;j++){
			if(!pd[b[j].id])continue;
			fx=find(b[j].x);
			fy=find(b[j].y);
			if(fx!=fy){
				ss++;
				sum+=b[j].w;
				f[fx]=fy;
			}
			if(ss==n+s-1)break;
			if(sum>=ans)break;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
