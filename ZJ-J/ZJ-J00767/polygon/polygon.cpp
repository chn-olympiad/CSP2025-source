#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=998244353;
ll n,k;
ll a[5005];
int check(int zt){
	ll i=1,sum=0,num=0,maxn=0;
	while(zt){
		num+=zt&1;
		sum+=a[i]*(zt&1);
		maxn=max(maxn,a[i]*(zt&1));
		i++;
		zt>>=1;
	}
	if(num>=3 and sum>maxn*2)return 1;
	else return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool ONE=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1 and ONE)ONE=1;
		else ONE=0;
	}
	if(ONE){
		ll sss=0;
		for(int i=n-2;i>=1;i--){
			sss+=((i-1)*(i)%M)/2%M;
		}
		cout<<sss+1;
		return 0;
	}
	ll ok=0;
	for(int i=0;i<=(int)pow(2,n);i++)ok=ok%M+check(i)%M;
	cout<<ok;
	return 0;
}
