#include<bits/stdc++.h>
using namespace std;
int t,n,a[300],b[300],c[300],p[100000],ans=0,k,z;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int m=1;m<=t;m++){
		cin>>n;

		if(n==2){
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];	
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int k=1;k<=n;k++){	
						if(a[i]+b[j]>ans&&a[i]+b[j]>=a[i]+c[k]&&a[i]+b[j]>=b[i]+c[k]) ans=a[i]+b[j];
						else if(a[i]+c[k]>ans&&a[i]+c[k]>=b[j]+c[k]) ans=a[i]+c[k];
						else if(b[j]+c[k]>ans) ans=b[j]+c[k];
					}
				}
			}
		}
		cout<<ans;
		ans=0;
	}
	
	return 0;
}
