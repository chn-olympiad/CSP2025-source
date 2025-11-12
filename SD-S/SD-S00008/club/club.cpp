#include<bits/stdc++.h>
using namespace std;
struct Node{
	int zd,cz,cd;
};
int v[5];
vector<Node>a[5];
int cmp(Node a,Node b){
	return a.cz>b.cz;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int mx=0,cx=0,t;
			for(int j=1;j<=3;j++){
				cin>>v[j];
				if(v[j]>mx){
					cx=mx;
					t=j;
					mx=v[j];
				}else if(v[j]>cx){
					cx=v[j];
				}
			}
			a[t].push_back({mx,mx-cx,cx});
		}
		int sum=0;
		for(int i=1;i<=3;i++){
			sort(a[i].begin(),a[i].end(),cmp);
			for(int j=0;j<a[i].size();j++){
				if(j<n/2)sum+=a[i][j].zd;
				else sum+=a[i][j].cd;
			}
			a[i].clear();
		}
		cout<<sum<<"\n";
	} 
	return 0;
}

