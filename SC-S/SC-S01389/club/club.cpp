#include<bits/stdc++.h>
using namespace std;
int T,n,a[10005],b[10005],c[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>n;
		int l=n/2,ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		sort(a+1,a+1+n);
		for(int i=n;i>n/2;i--)
			ans+=a[i];
		cout<<ans<<endl;
	}
	return 0;
}