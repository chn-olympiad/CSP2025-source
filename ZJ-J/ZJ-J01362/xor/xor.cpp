#include<bits/stdc++.h>
using namespace std;
const int C=2e6+10;
int b[C],n,k,x;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	memset(b,0x8f,sizeof(b));
	b[0]=0;
	int s=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		s^=x;
		ans=max(ans,b[s^k]+1);
		b[s]=max(b[s],ans);
	}
	cout<<ans<<endl;
	return 0;
}

