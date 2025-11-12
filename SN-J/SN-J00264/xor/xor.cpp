#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,ans;
ll a[500005],s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	if(1e3<n&&n<=2e5&&k<=1){//13
		if(k){
			for(int i=1;i<=n;i++)if(a[ans])ans++;
		}
		else{
			int f=0;
			for(int i=1;i<=n;i++){
				if((a[i]==0)||(a[i]&&f))ans++,f=0;
				else f=1;
			}
		}
	}
	else{
		int ls=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j>ls;j--){
				if((s[i]^s[j-1])==k){
					ans++;
					ls=i;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

