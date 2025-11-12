#include <bits/stdc++.h>

using namespace std;

int n,m,k,ans=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int b,c,d;
		cin>>b>>c>>d;
		ans += d;
	}
	for(int i=1;i<=k;i++){
		int cnt;
		cin>>cnt;
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			cnt += x;
		}
		if(cnt == 0){
			cout<<0;
			return 0;
		}
	}
	cout<<ans/2;
	return 0;
} 
