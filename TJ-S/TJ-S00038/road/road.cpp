#include<bits/stdc++.h>
using namespace std;
int v[10005],u[10005];
int w[10005],cj[15];
int a[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=0;j<k;j++){
		cin>>cj[j];
		for(int i=0;i<n;i++){
			cin>>a[j][i];
		}
	}
	for(int i=0;i<m;i++){
		int js=0;
		for(int j=i;j<m;j++){
			cj[v[i]]=1;
			cj[u[i]]=1;
			js+=w[j];
			for(int k=0;k<n;k++){
				if(cj[k]==0){
					break;
				}else{
					cout<<js;
					return 0;
				}
			}
		}
	}
	return 0;
}
