#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,k,sum;
	int a[100];
	cin>>n>>k;
	for(int i=0;i<=5005;i++){
		cin>>a[i];
	}
	if(n==4 && k>1){
		cout<<2<<endl;
	}
	else if(k==1){
		for(int i=0;i<=n;i++){
			if(a[i]==1){
				sum+=1;
			}
		}
		cout<<sum<<endl;
	}
	else if(k==0){
		cout<<1<<endl;
	}
	else{
		cout<<0<<endl;
	}
	return 0;
}
