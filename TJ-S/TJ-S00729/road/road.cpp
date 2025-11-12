#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
		int f=0;
	cin>>n>>m>>k;int c[m],p[n];
	for(int i=0;i<n;i++){
		int u,v,w;
		cin>>u>>v>>p[i];
		f+=w;
	}
	for(int i=0;i<m;i++){
		cin>>c[m];
	}
	if(k=0){
		cout<<f<<endl;
	}
	else{
		while(m){
			int sd=0,sd1=0;
			for(int i=0;i<n;i++){
				if(sd<p[i]){
					sd=p[i];
					sd1=i;
				}
			}
			f-=sd;
			p[sd1]=0;
		}
		cout<<f<<endl;
	}
	return 0;
}
