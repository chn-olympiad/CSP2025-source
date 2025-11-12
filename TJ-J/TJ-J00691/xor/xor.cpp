#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],b[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=a[i]^b[i-1];
	int pre=0,ans=0;
	for(int i=1;i<=n;i++){
		bool f=0;
		for(int j=pre+1;j<=i;j++)
			if(b[i]^b[j-1]==k)
			f=1,pre=i;
		ans+=f;
	}
	cout<<ans;
	return 0;
} 
