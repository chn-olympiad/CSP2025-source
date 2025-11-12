#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,a[200005][4],b[4];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int m=n/2;
		int x,y,z;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int mx=-1,ans=0;
		for(int i=1;i<=3;i++) b[i]=0;
		for(int i=1;i<=n;i++){
			int f=max(a[i][1],max(a[i][2],a[i][3]));
			mx=max(f,mx);
			int ff;
			if(f==a[i][1]) ff=1;
			if(f==a[i][2]) ff=2;
			if(f==a[i][3]) ff=3;
			if(b[ff]>=m){
				for(int j=1;j<i;j++){
					if(a[j][ff]<a[i][ff]){
						int maxm=-1;
						for(int k=1;k<=3;k++){
							maxm=max(maxm,a[j][k]);
						}
						if(maxm==a[j][ff]){
							ans-=maxm;
							ans+=a[i][ff];
							continue;
						}
						else continue;
					}
				}
			}
			else {
				b[ff]++;
				ans+=f;	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}