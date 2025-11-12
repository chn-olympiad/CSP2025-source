#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[10001],b[10001],c[10001];
int d[10001];
int x,y,z;
int ansa,ansb,ansc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				d[i]=1;
				x++;
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				d[i]=2;
				y++;
			}else if(c[i]>=a[i]&&c[i]>=b[i]){
				d[i]=3;
				z++;
			}
		}
		if(x+y>=z&&x+z>=y&&y+z>=x){
			for(int i=1;i<=n;i++){
				if(d[i]==1){
					ansa+=a[i];
				}else if(d[i]==2){
					ansb+=b[i];
				}else if(d[i]==3){
					ansc+=c[i];
				}
			}
			cout<<ansa+ansb+ansc<<endl;
		}
	}
	return 0;
}
