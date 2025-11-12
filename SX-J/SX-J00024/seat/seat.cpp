#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m;
int f[105],rf,ri;
bool cmp(int a,int b) 
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	cin>>n>>m;
	for(int i = 0;i<n*m;i++)
	{
		cin>>f[i];
	}
	rf = f[0];
	sort(f,f+n*m,cmp);
	for(int i = 0;i<n*m;i++)
	{
		if(f[i] == rf)
		{
			ri = i+1;
			break;
		}
	}
	cout<<rf<<" "<<ri<<endl;
	if(ri%n == 0)
	{
		cout<<ri/n<<" ";
		if((ri/n)%2 != 0)
		{
			cout<<(ri-1)%n+1;
		}
		else
		{
			cout<<n-n%(ri-1);
		}
	}
	else
	{
		cout<<ri/n+1<<" ";
		if((ri/n+1)%2 != 0)
		{
			cout<<(ri-1)%n+1;
		}
		else
		{
			cout<<n-n%(ri-1);
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
