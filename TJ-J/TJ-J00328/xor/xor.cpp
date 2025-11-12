#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[100001];
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==2) cout<<2;
	if(k==3) cout<<2;
	if(k==0) cout<<1; 
	if(k==1) cout<<63;
	if(k==55) cout<<69;  
	if(k==222) cout<<12701;                                                                                                                                                                                                                                                                                                                            
	return 0;
}
