#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<array>
#include<vector>
using namespace std;
int n,m,k;
array<int,3> edge[1000001];
array<int,3> e[110001];
int f[10010];
int siz[10010];
int c[11];
int a[11][10001];
vector<int> v;
inline int findf(int x){
	if(!f[x])return x;
	return f[x]=findf(f[x]);
}
long long ans=0;
inline void he(int x,int y){
	x=findf(x),y=findf(y);
	if(x==y)return;
	if(siz[x]>siz[y])swap(x,y);
	siz[y]+=siz[x];
	f[x]=y;
}
//int calc(int x){
//	int cnt=0;
//	while(x){
//		if(x&1)cnt++;
//		x>>=1;
//	}
//	return cnt;
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)siz[i]=1;
//	cerr<<m<<'\n';
	for(int i=1;i<=m;i++){
//		cerr<<i<<'\n';
		cin>>edge[i][1]>>edge[i][2]>>edge[i][0];
	}
	for(int i=0;i<k;i++){
//		cerr<<i<<'\n';
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(edge+1,edge+m+1);
	for(int i=1;i<=m;i++){
		if(findf(edge[i][1])==findf(edge[i][2]))continue;
		he(edge[i][1],edge[i][2]);
		ans+=edge[i][0];
		v.push_back(i);
	}
//	cout<<ans<<'\n';
	for(int i=1;i<(1<<k);i++){
//		cerr<<i<<'\n';
//		cerr<<n<<'\t'<<k<<'\n';
		for(int j=1;j<=n+k;j++){
//			cerr<<j<<' ';
			f[j]=0;
			siz[j]=0;
		}
		int kk=0;
		long long res=0;
		for(auto j:v){
			e[kk++]=edge[j];
		}
//		int w=calc(i);
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				res+=c[j];
				for(int l=1;l<=n;l++){
					e[kk++]={a[j][l],j+1+n,l};
				}
			}
		}
		stable_sort(e,e+kk);
//		cerr<<i<<'\n';
		for(int j=0;j<kk;j++){
//			cerr<<e[j][1]<<'\t'<<e[j][2]<<'\n';
			if(findf(e[j][1])==findf(e[j][2]))continue;
			he(e[j][1],e[j][2]);
			res+=e[j][0];
		}
		ans=min(ans,res);
//		cout<<k<<'\t';
//		cout<<res<<'\n';
	}
	cout<<ans<<endl;
//	fflush(stdout);
	return 0;
}
