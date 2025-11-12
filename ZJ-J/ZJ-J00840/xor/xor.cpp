#include<bits/stdc++.h>
using namespace std;
long long a[600000];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)s++;
	}
	if(k==1)cout<<s;
	else{
		int z=0,as=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				as++;
				z=0;
			}
			if(a[i]==1){
				if(z==1){
					as++;
					z=0;
				}
				else
				z=1;
			}
		}
		cout<<as;
	}
	return 0;
}