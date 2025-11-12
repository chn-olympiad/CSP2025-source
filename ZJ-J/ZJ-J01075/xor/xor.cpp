#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,al,l=1,r,op,all;
int a[N],b[N];
bool _;
int yihuo(int a,int b){
	int k=a&b,op=a|b;
	return op-k;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)
			_=true;
		all+=a[i];
	}
	if(!_ && k<=1){
		if(k==1)
			cout<<all;
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1)
					op++;
				else{
					all-=op/2;
					op=0;
				}
			}
			cout<<n-all+op/2;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			al++;
			l=i+1;
			r++;
		}
		else{
			r++;
			for(int j=l;j<=r;j++){
				b[j]=yihuo(a[i],b[j]);
				if(b[j]==k){
					l=r+1;
					al++;
					break;
				}
			}
		}
	}
	cout<<al;
	return 0;
}
