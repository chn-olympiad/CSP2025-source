
#include <bits/stdc++.h>
using namespace std;
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int main()
{
	int n,max,y,w;//y    j里面有几个人； w满意总值； 
	char a[4];
	
	n%2==0;
	
	cin>>n>>a[4];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			while(i++)
			{
			
			if(a[i][j]<a[i][j+1])
			{
				j=j+1;			
			}
			else
			{
				j+1=1;
			}
			a[i]=max(a[i]a[j],a[i][j+1]);
		}
		if(y>n/2)
		 {
			return a[i];
			a[i]=max(a[i][j-1],a[i][j]);
	}
		}
	}
	w+=a[i];
	cout<<w<<endl;
	return 0;
}
