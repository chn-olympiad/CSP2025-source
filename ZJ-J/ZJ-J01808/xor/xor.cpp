#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,ans;
int a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)flag=1;
	}
	if(flag==0){
		if(k==1)for(int i=1;i<=n;i++)if(a[i]==1)ans++;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}