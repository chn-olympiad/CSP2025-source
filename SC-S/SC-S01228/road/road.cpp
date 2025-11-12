#include<bits/stdc++.h>
#define pii pair<int,int>
#define mpi map<pii,int>
#define m_p make_pair
#define ll long long
using namespace std;
int n,m,k;
ll b[15][100005],d[100005],s;
mpi mp;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		mp[m_p(u,v)]=mp[m_p(v,u)]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	d[1]=2e9;
	for(int i=2;i<=n;i++){
		d[i]=1e9;
		if(mp[m_p(1,i)]){
			d[i]=mp[m_p(1,i)];
		}
		for(int j=1;j<=k;j++){
			if(d[i]>b[j][1]+b[j][i]+b[j][0]){
				d[i]=b[j][1]+b[j][i]+b[j][0];
				b[j][0]=0;
			}
		}
	}
	for(int i=1,t;i<n;i++){
		t=min_element(d+1,d+1+n)-d;
		s+=d[t];
		d[t]=2e9;
		for(int j=1;j<=n;j++){
			if(d[j]!=2e9){
				if(mp[m_p(t,j)]){
					d[j]=mp[m_p(t,j)];
				}
				for(int l=1;l<=k;l++){
					if(d[j]>b[l][t]+b[l][j]+b[l][0]){
						d[j]=b[l][t]+b[l][j]+b[l][0];
						b[l][0]=0;
					}
				}
			}
		}
	}
	cout<<s;
	return 0;
}