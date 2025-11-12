#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<pow(2,n);i++){
		int cnt=0;
		vector<int>e;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				e.push_back(a[j+1]);
				cnt++;
			}
		}
		if(cnt<3){
			continue;
		}
		int mx=-1e9,sm=0;
		for(int j=0;j<cnt;j++){
			mx=max(mx,e[j]);
			sm+=e[j];
		}
		if(sm>mx*2){
			m++;
		}
	}
	cout<<m;
	return 0;
}
