#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define lli long long
#define pr pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e4+30,M=1e6+10;
const lli inf=1e18;
int n,m,k,c[12],f[N],D;
struct node{
	int x,y,z;
}b[M],p[N],bb[N];
struct nooo{
	int x,id;
}a[12][N];
bool cmp1(nooo x,nooo y){
	return x.x<y.x;
}
bool cmp(node x,node y){
	return x.z<y.z;
}
int ask(int x){
	if(x==f[x])return x;
	return f[x]=ask(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
	sort(b+1,b+m+1,cmp);
	lli s=0;
	int mm=0;
	for(int i=1;i<=m;i++){
		int x=ask(b[i].x),y=ask(b[i].y);
		if(x==y)continue;
		s+=b[i].z;
		f[x]=y;
		p[++mm]={b[i].x,b[i].y,b[i].z};
	}
	for(int i=0;i<k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j].x),a[i][j].id=j;
		sort(a[i]+1,a[i]+n+1,cmp1);
	}
	lli ans=s;
	for(int i=1;i<1<<k;i++){
		lli ss=0;
		for(int i=1;i<=n-1;i++)b[i]=p[i];
		int nn=n;
		for(int j=0;j<k;j++){
			if(i&(1<<j)){
				++nn;
				ss+=c[j];
				int x=1,y=1;
				mm=0;
				for(int j=1;j<=n+k;j++)f[j]=j;
				while(x<=nn-2||y<=n){
					if(x>nn-2||(y<=n&&a[j][y].x<b[x].z)){
						int oa=ask(nn),ob=ask(a[j][y].id);
						if(oa==ob){
							y++;continue;
						}
						bb[++mm]={nn,a[j][y].id,a[j][y].x};
						f[oa]=ob;
						y++;
					}
					else {
						int oa=ask(b[x].x),ob=ask(b[x].y);
						if(oa==ob){
							x++;continue;
						}
						bb[++mm]=b[x];
						f[oa]=ob;
						x++;
					}
				}
				for(int i=1;i<nn;i++)b[i]=bb[i];
			}
		}
		for(int j=1;j<nn;j++){
			ss+=b[j].z;
		}
//		sort(b+1,b+mm+1,cmp);
//		for(int i=1;i<=mm;i++){
//			int x=ask(b[i].x),y=ask(b[i].y);
//			if(x==y)continue;
//			ss+=b[i].z;
//			f[x]=y;
//		}
//		for(int i=1;i<n;i++)ss-=max(0,e[i<<1].d-val[i]);
		ans=min(ans,ss);
	}
	cout<<ans;
	return 0;
}
