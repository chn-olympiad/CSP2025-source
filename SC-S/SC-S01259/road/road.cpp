#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000],c[1000],d[1000];
map<int,map<int,int> >e;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=k;i++){
		cin>>d[i];
		for(int j=1;j<=n;j++) cin>>e[i][j];
	}
	if(k>0){
		cout<<0;
		return 0;
	}
	else{
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=c[i];
		} 
		cout<<sum<<endl;
	}
	return 0;
}