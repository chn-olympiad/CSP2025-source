#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
int a[N],b[N],c[N];
int n;
int ans=0;
int main()
{
	int n;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i]>>b[i]>>c[i];	
	}
		sort(a+1,a+1+n);
		for(int i=n;i>n/2;i--) ans+=a[i];
		cout<<ans<<"\n";
	}
	return 0;
}
