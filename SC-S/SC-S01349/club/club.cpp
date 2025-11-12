#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100007];
int b[100007];
int c[100007];
int dp[100007];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int o1=0,o2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0)	o1=1;
			if(c[i]!=0)	o2=1;
		}	
		if(!o1){
			int sum=0;
			sort(a+1,a+n+1);
			for(int i=n/2+1;i<=n;i++)	sum+=a[i];
			cout<<sum<<"\n";
			continue;
		}
		if(!o2){
			int sum=0;
			for(int i=1;i<=n;i++)	sum+=max(a[i],b[i]);
			cout<<sum<<"\n";	
			continue;
		}
		int sum=0;
		for(int i=1;i<=n;i++)	sum+=max(a[i],max(b[i],c[i]));
		cout<<sum<<"\n";		
	}
	return 0;
} 