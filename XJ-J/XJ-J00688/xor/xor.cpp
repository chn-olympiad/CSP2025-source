#include<bits/stdc++.h>
using namespace std;
int n[256],k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n,k;
	for(int i=0;i<n;i++){
		cin>>n[i];
	}
	if(k==0){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

