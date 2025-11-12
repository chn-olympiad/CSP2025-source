#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,k;
int a[5000005],s[5000005],ans=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
//	cin>>a[1];
//	s[1]=a[1];
	int l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) s[i]=a[i];
		else s[i]=s[i-1]^a[i];
		if(a[i]==k){
			ans++;
			//cout<<i<<endl;
			l=i;
			continue;
		}
		for(int j=i-1;j>=l;j--){
			if((s[i]^s[j])==k){
				//cout<<i<<' '<<s[i]<<" "<<j<<" "<<s[j]<<endl<<k<<" "<<(s[i]^s[j])<<endl;
				ans++;
				l=i;
			}
		}
	}
	cout<<ans;
	return 0;
}
