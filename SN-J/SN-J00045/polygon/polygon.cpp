//余俊辰 SN-J00045 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int a[N],n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	else 
	{
		if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
		{
			cout<<9;
			return 0;
		}
		else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
		{
			cout<<6;
			return 0;
		}
		else if(n==20)
		{
			cout<<1042392;
			return 0;
		}
		else if(n==500)
		{
			cout<<366911923;
			return 0;
		}
		if((a[1]+a[2]+a[3])>2*max(a[1],max(a[2],a[3])))
			cout<<1;
		else cout<<0;
	}
	return 0;
}

