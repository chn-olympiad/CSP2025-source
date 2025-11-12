#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],answ=0,lai=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		for(int j=i;j>=lai;j--)
		{
//			cout<<ans<<"../.."<<endl;
			ans^=a[j];
//			cout<<ans<<"./"<<endl;
			if(ans==m)
			{
				answ++;
				lai=i+1;
//				cout<<i<<" "<<j<<" "<<ans<<endl;
				break;
			}
		}
	}
	cout<<answ;
	return 0;
}
