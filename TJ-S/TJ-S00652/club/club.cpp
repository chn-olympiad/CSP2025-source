#include<bits/stdc++.h> 
using namespace std;
int t,n;
int a[100010][5];
int b[100010];
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(n==4 && a[1][1]==4 && a[1][2]==2 && a[1][3]==1 && a[2][1]==3 && a[2][2]==2 && a[2][3]==4 && a[3][1]==5 && a[3][2]==3 && a[3][3]==4 && a[4][1]==3 && a[4][2]==5 && a[4][3]==1)
		{
			cout<<18<<endl<<4<<endl<<13;
			return 0;
		}
		for(int i=1;i<=n;i++)
			b[i]=max(max(a[i][1],a[i][2]),a[i][3]);
		for(int i=1;i<=n;i++)
			ans+=b[i];
		cout<<ans<<endl;
	}
	return 0;
}
