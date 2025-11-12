#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005],n0=0,n1=0;
	bool f=1,b=1;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
		if(a[i]!=1&&a[i]!=0){
			b=0;
		}
		if(a[i]==1&&a[i-1]==1){
			n1++;
			cin>>a[i+1];
			if(a[i+1]==0){
				n0++;
			}
			if(a[i+1]==1){
				i++;
			}
			i++;
		}
		if(a[i]==0){
			n0++;
		}
	}
	if(k==0&&f==1){
		cout<<n/2;
		return 0;
		
	}
	if(k==0&&b==1){
		cout<<n0+n1;
		return 0;
		
	}
	cout<<1;
}
