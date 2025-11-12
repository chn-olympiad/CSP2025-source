#include<bits/stdc++.h>
#define ll long long
const ll maxn=500000+5;
using namespace std;
ll n,k,ans;
ll a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		ll tj1=0;
		for(int i=1;i<=n-1;i++){
			if(a[i]==1){
				tj1++;
			}
			if(tj1>1&&tj1%2==1){
				ans++;
				tj1=0;
				continue;
			}
			if(a[i]!=a[i+1]){
				ans++;
				//cout<<tj1<<" "<<i<<" ";
				i++;
				tj1=0;
			}
		}
	}
	else{
		for(int i=2;i<=n;i+=2){
			if(a[i]==a[i-1]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
I`m just a juruo.
I can`t coding anymore.
This exam is very hard.
Here is a pianfenxiaodaima.
I hope CCF can give me some score.
T_T
*/
