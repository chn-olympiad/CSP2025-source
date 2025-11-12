#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
int x,y,z;
int xx,yy,zz;
int ans;
int sss;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		sss=0;
		cin>>n;
		
		int chu=n/2;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			if(x>y and x>z){
				if(xx<=chu){
					sss=x;
					xx++;	
					ans+=sss;
					continue;
				}
				if(xx>chu and y>z){
					sss=y;
					yy++;
					ans+=sss;
					continue;
				}
				if(xx>chu and z>y){
					sss=z;
					zz++;
					ans+=sss;
					continue;
				}
			}
			if(y>x and y>z){
				if(yy<=chu){
					sss=y;
					yy++;	
					ans+=sss;
					continue;
				}
				if(yy>chu and x>z){
					sss=x;
					xx++;
					ans+=sss;
					continue;
				}
				if(yy>chu and z>x){
					sss=z;
					zz++;
					ans+=sss;
					continue;
				}
			}
			if(z>y and z>x){
				if(zz<=chu){
					sss=z;
					zz++;	
					ans+=sss;
					continue;
				}
				if(zz>chu and y>x){
					sss=y;
					yy++;
					ans+=sss;
					continue;
				}
				if(zz>chu and x>y){
					sss=x;
					xx++;
					ans+=sss;
					continue;
				}
			}
		}
		cout<<ans;
	}

	
	
	
	return 0;
}