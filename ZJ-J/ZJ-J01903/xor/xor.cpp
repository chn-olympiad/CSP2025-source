#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
int a[500005];
int x0=0,x1=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) x1++;
		if(a[i]==0) x0++;
	}
	if(x1+x0==n){
		if(k==1){
			cout<<x1;
		}else if(k==0){
			cout<<x0;
		}else{
			cout<<"0";
		}
		return 0;
	}
	int s=0;
	int l=0;
	for(int i=1;i<=n;i++){
		ll x=a[i];
		if(x==k){
			s++;
			l=i;
//			cout<<i<<"\n";
			continue;
		}
		for(int j=i-1;j>l;j--){
//			cout<<x<<"-";
			x^=a[j];
//			cout<<x<<"\n";
			if(x==k){
				s++;
				l=i;
//				cout<<i<<" "<<j<<" "<<x<<"\n";
				break;
			}
		}
	}
	cout<<s;
	return 0;
}
