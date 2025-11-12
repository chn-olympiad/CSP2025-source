#include<bits/stdc++.h>
using namespace std;
int a_0,a_1,n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n,k;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x==1) a_1++;
		else a_0++;
	}
	if(k==1)cout<<a_1;
	else cout<<a_1/2+a_0/2+a_0%2;
	return 0;
}
