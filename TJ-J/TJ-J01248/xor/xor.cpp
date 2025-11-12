#include <bits/stdc++.h>
using namespace std;
int n,k,flag=0,sum=0;
int a[500100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			sum++;
		}
	}
	cout<<sum<<endl;
	
	
	return 0;
}
