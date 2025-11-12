#include<bits/stdc++.h>
using namespace std;
int a1[100005],a2[100005],a3[100005];
int n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int max[5][100005]={0},q,p,w;
		int c=0,ans=0,a=0,b=0,big=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			if(max[1][i]<a1[i]) max[1][i]=a1[i];
			if(max[2][i]<a2[i]) max[2][i]=a2[i];
			if(max[3][i]<a3[i]) max[3][i]=a3[i];
			if(max[1][i]>max[2][i] && max[1][i]>max[3][i]) q=1;
			else if(max[2][i]>max[1][i] && max[2][i]>max[3][i]) q=2;
			else if(max[3][i]>max[2][i] && max[3][i]>max[1][i]) q=3;
			if(a+1<=n/2 && q==1)
			{
				ans+=max[1][i];
				a++;
			}
			else if(b+1<=n/2 && q==2)
			{
				ans+=max[2][i];
				b++;
			}
			else if(c+1<=n/2 && q==3)
			{
				ans+=max[3][i];
				c++;
			}
		}
		cout<<ans;
	}
	return 0;
}
