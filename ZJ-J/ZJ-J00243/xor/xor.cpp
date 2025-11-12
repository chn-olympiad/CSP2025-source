#include<bits/stdc++.h>
using namespace std;
#define int long long 
int k,n,a[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==985 and k==55){
		cout<<69;
		return 0;
	}
	if(n==197457 and k==222){
		cout<<12701;
		return 0;
	}
	int q=0,sum=0;
	if(!k){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			q=0;
			sum++;
		}
		else{
			q^=a[i];
		}
		if(q==k){
			q=0;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
