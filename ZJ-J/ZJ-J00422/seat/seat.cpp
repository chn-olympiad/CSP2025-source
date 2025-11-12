#include<bits/stdc++.h>
using namespace std;
long long a[105],b;
long long ans[15][15];
bool flag[105];
bool dir=true;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+(n*m)+1,greater<int>());
	long long c=1,r=1;
	for (int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			cout<<r<<" "<<c;
		}
		if(i%n==0)
		{
			r++;
			if(dir==true)
			{
				dir=false;
			}
			else
			{
				dir=true;
			}
		}else
		{
			if(dir==true)
			{
				c++;
			}
			else
			{
				c--;
			}
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//2*2
// 1:1 1
// 2:1 2
// 3:1 3
// 

