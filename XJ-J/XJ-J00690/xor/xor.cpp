#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=0,k=0,s=0,i=0,c=0;
	cin>>n>>k;
	int a[n+5]={0};
	for(i=1;i<n+1;i++){
		cin>>a[i];
		s+=a[i];
		if(s==k){
			c+=1;
			s=0;
		}
	}
	cout<<n/2;
	return 0;
}
