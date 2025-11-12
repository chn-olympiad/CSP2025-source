#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+4;
int n,m,k,x,y,q,cnt;
int c[14],a[14][10004];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>x>>y>>q;
		cnt+=q;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	cout<<cnt;
	return 0;
}
