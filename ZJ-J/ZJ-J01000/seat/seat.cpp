#include<bits/stdc++.h>
using namespace std;
pair<int,int> g[109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>g[i].first;
		g[i].second=i;
		g[i].first=-g[i].first;
	}
	sort(g+1,g+1+n*m);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				if(g[++cnt].second==1){
					cout<<i<<" "<<j;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(g[++cnt].second==1){
					cout<<i<<" "<<j;
				}
			}
		}
	}
	return 0;
}
