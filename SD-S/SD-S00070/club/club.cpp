#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,a1,a2,a3,d;
pair<int,int> a[3];
vector<int> f[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		for(int i:{0,1,2})
			f[i].clear();
		d=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j:{0,1,2}){
				cin>>a[j].first;
				a[j].second=j;
			}
			sort(a,a+3);
			d+=a[2].first;
			f[a[2].second].push_back(a[2].first-a[1].first);
		}
		for(int i:{0,1,2}){
			if(f[i].size()>n/2){
				sort(f[i].begin(),f[i].end());
				for(int j=0;j<f[i].size()-n/2;j++)
					d-=f[i][j];
			}
		}
		cout<<d<<'\n';
	}
	return 0;
}
