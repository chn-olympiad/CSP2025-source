#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a,c=0,e,f;
	int d[3]={};
	cin>>a;
	int g[a]={};
	for(int i=0;i<a;i++){
		int r;
		cin>>r;
		int b[3][r];
		int ll[r]={};
		for(int j=0;j<3;j++){
			for(int k=0;k<r;k++){
				cin>>b[j][k];
			}
		}
		for(int o=0;o<r;o++){
			for(int j=0;j<3;j++){
				for(int k=0;k<r;k++){
					if(b[j][k]>c and d[j]<=r/2 and ll[k]!=1){
						c=b[j][k];
						e=j;
						f=k;
					}
				}
			}
			g[i]+=c;
			b[e][f]=0;
			ll[f]=1;
			d[e]+=1;
		}
	}
	for(int t=0;t<a;t++){
		cout<<g[t]<<endl;
	}
	return 0;
}
