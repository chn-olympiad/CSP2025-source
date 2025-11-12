#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+10;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> c(k+1,0);
	vector< vector<int> > w(m+1,vector<int>(3,0)),cw(k+1,vector<int>(m+1,0));
	for(int i=0;i<m;++i){
		for(int j=0;j<3;++j){
			cin>>w[i][j];
		}
	}
	for(int i=0;i<k;++i){
		cin>>c[i];
		for(int j=0;j<n;++j){
			cin>>cw[i][j];
		}
	}
	long long ans;
	long long min1=1e7;
	for(int i=0;i<n;++i)min1=min(min1,w[i][2]*1ll);
	for(int i=0;i<n;++i)ans+=w[i][2];
	cout<<ans-min1;
	return 0;
}
