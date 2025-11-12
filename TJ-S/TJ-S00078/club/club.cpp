#include<bits/stdc++.h>
using namespace std;
int arr[1000005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a,b,c,dx,y,z;
	cin>>t>>n;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			int x=0;
			if(a>b&&a>c){
				d=a;
			}else if(b>a&&b>c){
				d=b;
			}else if(c>a&&c>b){
				d=c;
			}
			x+=d;
		}
		for(int j=1;j<=n;j++){
			cin>>n;
			cin>>a>>b>>c;
			int y=0;
			if(a>b&&a>c){
				d=a;
			}else if(b>a&&b>c){
				d=b;
			}else if(c>a&&c>b){
				d=c;
			}
			y+=d;
		}
		for(int j=1;j<=n;j++){
			cin>>n;
			cin>>a>>b>>c;
			int z=0;
			if(a>b&&a>c){
				d=a;
			}else if(b>a&&b>c){
				d=b;
			}else if(c>a&&c>b){
				d=c;
			}
			z+=d;
		}
		cout<<x<<y<<z<<endl;
	}
	
	return 0;
}
