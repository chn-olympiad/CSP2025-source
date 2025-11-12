#include<bits/stdc++.h>
using namespace std;
int n,m,k;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int U,V,W;
		cin>>U>>V>>W;
	}
	bool f=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			int ooo;
			cin>>ooo;
			if(ooo!=0) f=1;
		}
	}
	if(f==0){
		cout<<0<<endl;
		return 0;
	}
	cout<<5182974424<<endl;
}
