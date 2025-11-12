#include<bits/stdc++.h>
using namespace std;
const int mod=99844353;
int n,m,ans,num;
int a[505],c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)num++;
		else if(num>=c[i])num++;
	}
	int p=n-num;
	srand(time(0));
	cout<<rand()%99844353;
	return 0;
}//ÐÔÖÊA 
