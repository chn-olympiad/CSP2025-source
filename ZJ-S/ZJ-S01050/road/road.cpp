#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
const int M=3e5+10;
long long n,m,k;
struct node{
	long long x,y,z;
	bool operator <(const node &cmp)const{
		return z<cmp.z;
	}
}a[M],d[M],e[M];
struct node2{
	long long sum,id;
	bool operator <(const node2 &cmp)const{
		return sum<cmp.sum;
	}
}b[15][N];
long long c[N];
int fa[M];
int tot;
inline int find(int x){
	return x==fa[x] ? x : fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
	}
	sort(a+1,a+m+1);
	for(int i=0;i<k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&b[i][j]);
			b[i][j].id=j;
		}
		sort(b[i]+1,b[i]+n+1);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	long long mx=0,ret=0;
	for(int i=1;i<=m;i++){
		int ax=find(a[i].x);
		int ay=find(a[i].y);
		if(ax!=ay){
			fa[ax]=ay;
			mx=max(mx,a[i].z);
			ret+=a[i].z;
			d[++tot]=a[i];
		}
	}
	if(k==0){
		cout<<ret;
		return 0;
	}
	long long mn=ret;
	for(int msk=1;msk<(1<<k);msk++){
		int tot2=0;
		for(int i=1;i<=tot;i++){
			e[++tot2]=d[i];
		}
		long long sum=0,f=0,mxx=mx;
		for(int i=0;i<k;i++){
			if(msk&(1<<i)){
				sum+=c[i];
				bool f=0;
				for(int j=2;j<=n;j++){
					int u=b[i][1].sum+b[i][j].sum;
					if(u>=mxx){
						f=1;
						break;
					}else{
						e[++tot2].x=b[i][1].id;
						e[tot2].y=b[i][j].id;
						e[tot2].z=u;
					}
				}
				if(f==0)mxx=b[i][1].sum+b[i][n].sum;
			}
		}
		sort(e+1,e+tot2+1);
		for(int i=1;i<=n;i++)fa[i]=i;
		long long cnt=0,sum2=sum;
		for(int i=1;i<=tot2;i++){
			int ax=find(e[i].x);
			int ay=find(e[i].y);
			if(ax!=ay){
				cnt++;
				fa[ax]=ay;
				sum2+=e[i].z;
			}
			if(cnt==n-1)break;
		}
		mn=min(mn,sum2);
	}
	cout<<mn;
	return 0;
}
//(2^k)*k*n    ?