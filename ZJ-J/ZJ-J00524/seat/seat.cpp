#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],u,t;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	u=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==u)
		{
			t=i;break;
		}
	}
	int q=1,w=1;
	for(int i=1;i<t;i++)
	{
		if(q%2==1)
		{
			if(w==m)
				q++;
			else
				w++;
		}
		else
		{
			if(w==1)
				q++;
			else
				w--;
		}
	}
	cout<<q<<' '<<w<<endl;
	return 0;
}
