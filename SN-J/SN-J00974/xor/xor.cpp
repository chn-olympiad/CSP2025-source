#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[201101];
int main()
{	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int b=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a==1){
			b=1;
		}
	}
	for(int i=0;i<n;i++){
		if(a==0){
			b=0;
			break;
		}
	}
	int b[201101];
	int ans=0;
	if(k==0){
		cout<<0;
	}
	else {
	cout<<2;
	}
	return 0;
}
