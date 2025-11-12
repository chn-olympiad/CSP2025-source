//SN-J01085  闫卜予  西安高新一中沣东中学初中校区 

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll a[501000],s[501000];
ll n,k;
ll l=1,r=1,ans=0,sum=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1] xor a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j] xor s[i-1])==k){
				ans++;
				i=j;
				break;		
			}
		}
	}
	cout<<ans;
	return 0;
}
