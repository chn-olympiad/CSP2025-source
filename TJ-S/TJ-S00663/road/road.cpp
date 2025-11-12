#include<bits/stdc++.h>

using namespace std;

long long n,m,k,u[1000001],v[1000001],w[1000001],c[11][10001],p[10001],ans;
long long s[10001][10001];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cout<<n<<' '<<m<<' '<<k<<endl;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		cout<<u[i]<<' '<<v[i]<<' '<<w[i]<<endl;
		s[u[i]][v[i]]=w[i];
		s[v[i]][u[i]]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		cout<<c[i][0]<<' ';
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			cout<<c[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		long long minn=1000000000;
		for(int j=1;j<=k;j++){
			minn=min(minn,c[j][u[i]]+c[j][v[i]]);
		}
		s[u[i]][v[i]]=min(s[u[i]][v[i]],minn);
		s[v[i]][u[i]]=min(s[v[i]][u[i]],minn);
	}
	for(int i=1;i<=n;i++){
		long long minnn=1000000000,x=0,y=0;
		for(int j=1;j<=n;j++){
			if(j==i){
				cout<<0<<' ';
				continue;
			}
			if(s[i][j]==0){
				long long minn=1000000000;
				for(int l=1;l<=k;l++){
					minn=min(c[l][i]+c[l][j],minn);
				}
				s[i][j]=-1;
				s[j][i]=minn;

				minnn=min(minn,minnn);
			}else{
				if(minnn<s[i][j]){
					x=i;
					y=j;
				}
				minnn=min(minnn,s[i][j]);
			}
			cout<<s[i][j]<<' ';
		}
		cout<<endl;
		s[x][y]=-1;
		if(s[y][x]!=-1){
			ans+=minnn;
		}
		cout<<minnn<<endl;
	}
	cout<<ans;
	return 0;
} 
