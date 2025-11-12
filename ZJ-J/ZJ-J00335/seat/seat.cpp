#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1,Rfen;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int a;
			cin>>a;
			if(i==0&&j==0)Rfen=a;
			else if(a>Rfen)cnt++;
		}
	}
	int lie=(cnt+m-1)/m;
	cout<<lie<<" ";
	int yu=cnt%m;
	if(yu==0)yu=m;
	if(lie%2==1)cout<<yu;
	else cout<<m-yu+1;
	return 0;
}
