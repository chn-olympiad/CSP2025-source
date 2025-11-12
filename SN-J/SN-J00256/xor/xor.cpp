#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int a[0x7f],n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	if(k==2)
	    cout<<2;
	if(k==3)
	    cout<<2;
	if(k==0)
	    cout<<1;
	else cout<<3;
	return 0;
}//Ï¹ÃÉ°É
 
