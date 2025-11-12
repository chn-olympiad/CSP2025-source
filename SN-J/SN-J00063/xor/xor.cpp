//SN-J00063
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll fyc=5e5+5;
ll ans,n,k,a[fyc],s[fyc],l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=l;j<i;j++)
			if((s[i]^s[j])==k){
				ans++,l=i;
				break;
			}
	cout<<ans;
	return 0;
}
