#include<bits/stdc++.h>

using namespace std;
int t,n,ans,k,a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			int x,y,z;
			x=a[i];
			y=b[i];
			z=c[i];
			k=max(x,y);
			k=max(k,z);
			ans+=z;
		}
		cout<<ans<<endl;
	}
	return 0;
}
