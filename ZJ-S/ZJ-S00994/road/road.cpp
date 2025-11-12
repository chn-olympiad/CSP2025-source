#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int N=1e4+100;
int n,m,k,f[N],w[N],s[N],lg[N],c[11],d[11],top;
ll ans,sum;
//vector<int> a[N];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
struct node{
	int x,y,z;
	bool operator<(const node& e)const{
		return z<e.z;
	}
}b[11][N],ed[1100005];
int cnt,c2;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	int x,y,z;
	for (int i=1;i<=m;++i){
		++cnt;
		cin>>ed[cnt].x>>ed[cnt].y>>ed[cnt].z;
	}
	for (int i=0;i<k;++i){
		cin>>w[i];
		for (int j=0;j<n;++j)cin>>b[i][j].z,b[i][j].x=i+1,b[i][j].y=j+1;
		sort(b[i],b[i]+n);
	}
	sort(ed+1,ed+cnt+1);
	for (int i=1;i<=n;++i)f[i]=i;
	for (int i=1,j=0;j<n-1;++i){
		x=ed[i].x;y=ed[i].y;z=ed[i].z;
		x=find(x);y=find(y);
		if (x!=y)++j,f[x]=y,ans+=z,b[10][c2++]=ed[i];//
	}
	bool flag=1;
	for (int i=0;i<k;++i){
		if (b[i][0].z>0||w[i]>0){
			flag=0;break;
		}
	}
	if (flag){
		sum=0;
		for (int i=0;i<c2;++i)ed[i]=b[10][i];
		cnt=c2;
		for (int i=0;i<k;++i){
			for (int j=0;j<n;++j)ed[cnt++]={b[i][j].x+n,b[i][j].y,b[i][j].z};
		}
		sort(ed,ed+cnt);
		for (int i=1;i<=n+k;++i)f[i]=i;
		for (int i=0,j=0;j<n+k-1;++i){
			x=ed[i].x;y=ed[i].y;z=ed[i].z;
			x=find(x);y=find(y);
			if (x!=y)++j,f[x]=y,sum+=z;
		}
		cout<<sum;
		cout.flush();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for (int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	for (int i=1;i<(1<<k);++i){
		for (int j=1;j<=n+k;++j)f[j]=j;
		sum=s[i]=s[i^(i&-i)]+w[lg[i&-i]];
		for (int i=0;i<c2;++i)ed[i]=b[10][i];
		cnt=c2;
		int tt=0;
		for (int j=0;j<k;++j){
			if ((i&(1<<j))==0)continue;
			++tt;
			for (int t=0;t<n;++t)ed[cnt++]={b[j][t].x+n,b[j][t].y,b[j][t].z};
		}
		sort(ed,ed+cnt);
		for (int j=1;j<=n+k;++j)f[j]=j;
		for (int j=0,t=0;t<n+tt-1;++j){
			x=ed[j].x;y=ed[j].y;z=ed[j].z;
			x=find(x);y=find(y);
			if (x!=y)++t,f[x]=y,sum+=z;
		}
		ans=min(ans,sum);
		/*
		for (int j=1;j<=n+k;++j)f[j]=j;
		sum=s[i]=s[i^(i&-i)]+w[lg[i&-i]];
		top=0;for (int j=0;j<=10;++j)d[j]=0;
		for (int j=0;j<10;++j)if(i&(1<<j))c[top++]=j;
		//c[10]=10;
		int ma;
		for (int j=0;j<n+top-1&&sum<ans;){
			ma=10;
			for (int t=0;t<top;++t){
				x=c[t];y=d[x];
				if (y<n&&(d[ma]>=c2||b[x][y]<b[ma][d[ma]])){
					ma=x;
				}
			}
			node t=b[ma][d[ma]];
			x=t.x;y=t.y;z=t.z;
			x=find(x+(ma!=10)*n);y=find(y);
			if (x!=y){
				sum+=z;
				f[x]=y;
				++j;
				if (sum>=ans)break;
			}
			++d[ma];
		}
		ans=min(ans,sum);
		*/
	}
	cout<<ans;
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}