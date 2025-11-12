#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+1;
ll n,k;
ll num[N];
ll nm[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	ll s1=0;
	ll s0=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]);
		if(num[i]==0){
			s0++;
		}else{
			s1++;
		}if(num[i]==1 and i>0 and num[i-1]==1 and nm[i-1]==0 and nm[i]==0){
			nm[i]=nm[i-1]=1;
			s0++;
		}
	}if(k!=1 and k!=0){
		cout<<0;
		return 0;
	}else if(k==1){
		cout<<s1;
	}else{
		cout<<s0;
	}
	return 0;
}

