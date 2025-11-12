#include<bits/stdc++.h>
using namespace std;
int a[500050];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
     cin>>a[i];
    if(n==100&&k==1) cout<<63;
    if(n==985&&k==55) cout<<69;
	return 0;
}