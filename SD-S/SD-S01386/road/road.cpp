#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
struct Ed{
	int ne;
	long long le;
};
bool f[15],flag[N],fl[N][N];
bool cmp(Ed x,Ed y){
	if (flag[x.ne]&&flag[y.ne]==0)
		return 0;
	else if (flag[x.ne]==0&&flag[y.ne])
		return 1;
	return x.le<y.le;
}
int n,m,k;
long long c[15],a[15][N];
long long ed[N][N];
Ed mied[N];
long long ans=-1,num;
void smtr(int be){
	for (int i=1;i<=n;i++)
		mied[i].le=INT_MAX,flag[i]=0;
	flag[1]=1;
//	cout<<f[1]<<endl;
	for (int i=1;i<=n;i++){
		if (f[1]!=1)
			mied[i].le=ed[1][i],mied[i].ne=i;
		else
			mied[i].le=c[1]+a[1][i],mied[i].ne=i;
	}
	num=0;
	for (int i=1;i<n;i++){
		sort(mied+1,mied+1+n,cmp);
		num=num+mied[1].le;
		flag[mied[1].ne]=1;
		for (int j=2;j<=n-i;j++)
			if (flag[j]==0){
				if (mied[1].ne<=k&&f[mied[1].ne])
					mied[j].le=min(mied[j].le,c[mied[1].ne]+a[mied[1].ne][mied[j].ne]);
				else
					mied[j].le=min(mied[j].le,ed[mied[1].ne][j]);
			}
		mied[1].le=INT_MAX;
	}
}
void dfs(int step){
	if (step==k+1){
		smtr(1);
//		cout<<num<<endl;
		if (ans==-1)
			ans=num;
		else
			ans=min(ans,num);
		return ;
	}
	dfs(step+1);
	f[step]=1;
	dfs(step+1);
	f[step]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		ed[u][v]=w;
		ed[v][u]=w;
		fl[u][v]=1;
		fl[v][u]=1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (fl[i][j]==0)
				ed[i][j]=INT_MAX;
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
