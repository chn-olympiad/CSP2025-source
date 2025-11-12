#include<bits/stdc++.h>
using namespace std;
int t,n,p[3];
int v[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int f = 1;f<=n;f++){
			for(int o = 0;o<=2;o++){
				cin>>p[o];
			}
			for(int o = 0;o<10;o++){
				if(p[o]>p[o++]){
					p[o++]=p[o];
				}
			}
			cout<<p[2]<<" ";
		}
	}
}
