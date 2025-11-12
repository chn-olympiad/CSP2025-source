#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,z,ans,da,sum,s,l,ll,lx,ly;
long long d[1001][1001],c[100001],b[11][10001],f[100001],ff[100001],fff[11][10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)d[i][j]=-1;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		d[x][y]=z;
		d[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]==1)continue;
		ans=sum=1e10;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(d[i][j]!=-1&&d[i][j]<ans){
				ans=d[i][j];
				l=j;
			}
			for(int r=1;r<=k;r++){
				s=c[r];
				if(ff[r]==1)s=0;
				if(fff[r][j]==0)s+=b[r][j];
				if(fff[r][i]==0)s+=b[r][i];
				if(s<sum){
					sum=s;
					ll=r;
					lx=j;
					ly=i;
				}
			}
		}
		if(ans>sum){
			da+=ans;
			f[l]=1;
		}
		else{
			ff[ll]=1;
			f[lx]=1;
			fff[ll][lx]=1;
			fff[ll][ly]=1;
		}
	}
	cout<<da;
	return 0;
}
