#include<bits/stdc++.h>
using namespace std;
const int N=1e6+15,M=1e4+15;
struct node{
	int x,y,z;
}a[N],b[N];
int fat[M];
bool cmp(node xx,node yy){
	return xx.z<yy.z;
}
int zbb(int x){
	if(fat[x]==x) return x;
	return fat[x]=zbb(fat[x]);
}
//int fat[M];
int c[15];
//int d[15][M];
struct node2{
	int id,x,val;
}d[N];
bool cmp2(node2 xx,node2 yy){
	return xx.val<yy.val;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	for(int i=1;i<=n;++i) fat[i]=i;
	sort(a+1,a+1+m,cmp);
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=m;++i){
		int x=a[i].x,y=a[i].y;
		int xx=zbb(x),yy=zbb(y);
		if(xx!=yy){
			fat[xx]=yy;
			++cnt;
			ans+=a[i].z;
			b[cnt].x=a[i].x;
			b[cnt].y=a[i].y;
			b[cnt].z=a[i].z;
		}
		if(cnt==n-1) break;
	}
	int nn=n-1;
	int nm=0;
	for(int i=1;i<=k;++i){
		scanf("%d",c+i);
		for(int j=1;j<=n;++j){
			++nm; 
			scanf("%d",&d[nm].val);
			d[nm].x=j;
			d[nm].id=i;
		}
	}
	sort(d+1,d+1+nm,cmp2);
	bool t[15]={}; 
	for(int kk=0;kk<(1<<k);++kk){
		long long sum=0;
		for(int j=1;j<=10;++j) t[j]=0;
		int cnt2=0;
		for(int j=0;j<k;++j){
			if(((kk>>j)&1)){
				sum+=c[j+1];
				t[j+1]=1;
				cnt2++;
			}
		}
		int cnt=0,j1=1,j2=1;
		for(int i=1;i<=n+k;++i) fat[i]=i;
		while(1){
			while(j2<=nm&&t[d[j2].id]==0) ++j2;
			if(j2<=nm&&j1<=nn){
				if(d[j2].val<b[j1].z){
					int x=d[j2].id+n,y=d[j2].x;
					int xx=zbb(x),yy=zbb(y);
					if(xx!=yy){
						++cnt;
						fat[xx]=yy;
						sum+=d[j2].val;
					}
					++j2; 
				}
				else{
					int x=b[j1].y,y=b[j1].x;
					int xx=zbb(x),yy=zbb(y);
					if(xx!=yy){
						++cnt;
						fat[xx]=yy;
						sum+=b[j1].z;
					}
					++j1;
				}
			} 
			else if(j2<=nm){
				int x=d[j2].id+n,y=d[j2].x;
				int xx=zbb(x),yy=zbb(y);
				if(xx!=yy){
					++cnt;
					fat[xx]=yy;
					sum+=d[j2].val;
				}
				++j2; 
			}
			else{
				int x=b[j1].y,y=b[j1].x;
				int xx=zbb(x),yy=zbb(y);
				if(xx!=yy){
					++cnt;
					fat[xx]=yy;
					sum+=b[j1].z;
				}
				++j1;
			}
			if(cnt==n+cnt2-1) break;
		}
		ans=min(ans,sum); 
	}
	printf("%lld\n",ans);
	return 0;
}
