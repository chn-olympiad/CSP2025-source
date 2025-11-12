#include <bits/stdc++.h>
using namespace std;
int sat[100010][4];
int main()
{
	freopen("club.in",r,stdin);
	freopen("club.out",w,stdout);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>sat[i][j];
		for(int i=1;i<=n;i++)
			for(int j=n;j>=i;j--)
				if(sat[i][1]<sat[j][1])
					swap(sat[i][1],sat[j][1]);
		for(int i=1;i<=n/2;i++)
			ans+=sat[i][1];
		cout<<ans<<endl;
	}
	return 0;
}
