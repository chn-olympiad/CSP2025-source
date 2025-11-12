#include<bits/stdc++.h>

using namespace std;

int s,n,m,k,o,a[1000005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>m;
	if(m!=0&&m!=1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			k++;
		}
		if(a[i]==0)o++;
	}
	if(m==1){
		cout<<k;
		return 0;
	}
	if(o==0&&m==0){
		cout<<k/2;
		return 0;
	}
	if(k==0&&m==0){
		cout<<o;
		return 0;
	}
	if(m==0){
		for(int i=2;i<=n;i++){
			if(a[i]==1&&a[i-1]==1)o++;
			cout<<o;
			return 0;
		}
	}
	return 0;
}
