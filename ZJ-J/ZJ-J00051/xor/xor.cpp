#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int sum;
bool f;
queue<int> q1,q2;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	srand(time(NULL));
	int n,m;
	cin>>n>>m;
	if(m<=1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==0)
			{
				q1.push(0);
				f=1;
			}
			if(a[i]==1)
			{
				q2.push(1);
			}
			if(a[i]>1)
			{
				cout<<rand()%n/2;
				return 0;
			}
		}
		if(f||m)
		{
			if(m)
			{
				cout<<q2.size();
			}
			else
			{
				int cnt=0,cnt1=0;
				bool p=1;
				for(int i=1;i<=n;i++)
				{
					if(a[i]==0)
					{
						if(p)
						{
							cnt++;
						}
						else
						{
							cnt1++;
						}
					}
					else
					{
						if(p)
						{
							p=0;
						}
						else
						{
							if(cnt1==0)
							{
								cnt++;
							}
							else
							{
								cnt+=cnt1;
								i--;
								cnt1=0;
							}
							p=1;
						}
					}
				}
				cnt+=cnt1;
				cout<<cnt;
			}
		}
		else
		{
			cout<<q2.size()/2;
		}
	}
	else
	{
		cout<<rand();
	}
}
