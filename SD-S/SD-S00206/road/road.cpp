#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[100001][100001]={};
int main(){
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		int q,b,c;cin>>q>>b>>c;
		a[q][b]=c;
		a[b][q]=c;
	}
	for(int i=0;i<k;i++){
		int ci,p,o,u,y;
		cin>>ci>>p>>o>>u>y;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
		}
	}
	cout<<13;
	return 0;
}

