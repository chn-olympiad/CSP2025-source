#include<bits/stdc++.h>
using namespace std;
long long a[500010],c[500010],s[500010],n,l,f,k,ans,mx;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		s[i]=s[i-1]^a[i];
	}
	if(mx>1){
		l=1;
		for(long long i=1;i<=n;i++){
			for(long long j=i;j>=l;j--){
				if((s[i]^s[j-1])==k){
					ans++;
					l=i+1;
					break;
				}
			}
		}
		cout<<ans;
	}
	else{
		if(k==0){
			for(long long i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else if(a[i-1]==1&&!f) ans++,f=2;
				if(f) f--;
			}
			cout<<ans;
		}
		else{
			for(long long i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;
		}
	}
	return 0;
}