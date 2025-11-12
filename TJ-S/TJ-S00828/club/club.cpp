#include<bits/stdc++.h>
using namespace std;
int t,n,a[105],b[105],c[105],x,y,z,m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","u",stdout);
	cin>>t>>n;
	while(t--){
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]&&x<=n/2){
				x++;
				m=m+a[i];
				break;
			}
			else a[i]=0;
			if(b[i]>=a[i]&&b[i]>=c[i]&&y<=n/2){
				y++;
				m=m+b[i];
				break;
			}
			else b[i]=0;
			if(c[i]>=a[i]&&c[i]>=b[i]&&z<=n/2){
				z++;
				m=m+c[i];
				break;
			}
			else c[i]=0;
		}
	}
	cout<<m<<endl;
	return 0;
}
