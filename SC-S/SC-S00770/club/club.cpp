#include<bits/stdc++.h>
using namespace std;
int a[100100];
int b[100100];
int c[100100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	int n;
	while(t!=0){
		t--;
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>a[i]>>b[i]>>c[i];
		}
		int o=0;
		int l;
		int u;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(i==1) l=a[1];
				if(i==2) l=b[1];
				if(i==3) l=c[1];
				if(j==1) u=a[2];
				if(j==2) u=b[2];
				if(j==3) u=c[2];
				if(u+l>o&&i!=j){
					o=u+l;
				}
			}
		}
		cout <<o<<endl;
	} 
	return 0;
} 