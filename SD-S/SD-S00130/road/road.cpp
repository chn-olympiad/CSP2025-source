#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[15][100010],p[100010],d[100010],val[100010],c[100010],siz[100010],st[100010];
pair<int,pair<int,int> > que[1000010],qq[1000010],tmp[1000010];
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
	return x;
}
int find(int x){
	return p[x]^x?p[x]=find(p[x]):x;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,mm;
	cin>>n>>m>>mm;
	for(int i=1;i<=m;i++)que[i].second.first=read(),que[i].second.second=read(),que[i].first=read();
	sort(que+1,que+m+1);
	int idxx=0;
	for(int i=1;i<=mm;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)a[i][j]=read(),tmp[++idxx]=make_pair(a[i][j],make_pair(i+n,j));
	}
	sort(tmp+1,tmp+idxx+1);
	int tans=(int)(1e18);
	for(int i=0;i<(1<<mm);i++){
		int ans=0,idx=0;
		for(int j=0;j<mm;j++)if(i>>j&1)ans+=c[j+1];
		for(int j=1;j<=idxx;j++)if(i>>(tmp[j].second.first-n-1)&1)qq[++idx]=tmp[j];
		for(int j=1;j<=n+mm;j++)p[j]=j,siz[j]=1,d[j]=0;
		int ii=1,jj=1;
		while(ii<=m||jj<=idx){
			if(jj>idx||(ii<=m&&jj<=idx&&que[ii].first<qq[jj].first)){
				int x=find(que[ii].second.first),y=find(que[ii].second.second);
				if(siz[x]>siz[y])swap(x,y);
				if(x^y)p[x]=y,siz[y]+=siz[x],ans+=que[ii].first,st[ii]=1;
				ii++;
			}
			else{
				int x=find(qq[jj].second.first),y=find(qq[jj].second.second);
				if(siz[x]>siz[y])swap(x,y);
				if(x^y)p[x]=y,siz[y]+=siz[x],ans+=qq[jj].first,d[qq[jj].second.first-n]++,val[qq[jj].second.first-n]=qq[jj].first;
				jj++;
			}
		}
		for(int j=1;j<=mm;j++)if(d[j]==1)ans-=val[j];
		tans=min(tans,ans);
		if(!i){
			int tt=0;
			for(int i=1;i<=m;i++)if(st[i])que[++tt]=que[i];
			m=tt;
		}
	}
	cout<<tans;
}
