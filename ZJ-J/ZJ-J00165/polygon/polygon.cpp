#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
long long n,a[5005],q,sum;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q=max(q,a[i]);
		sum+=a[i];
	}
	if(n==3){
		if(sum>q*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
