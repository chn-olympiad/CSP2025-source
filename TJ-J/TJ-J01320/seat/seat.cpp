#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b)
{
	if(a<b) return false;
	return true;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m ;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i] ;
	}
	int a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=1;
	bool t_f=0;
	for(int i=2;a[i-1]!=a1;i++)
	{
		if(!t_f)
		{
			if(l==n)
			{
				r++;
				t_f=1;
			}
			else
			{
				l++;
			}
		}
		else
		{
			if(l==1)
			{
				r++;
				t_f=0;
			}
			else
			{
				l--;
			}
		}
	}
	cout << r << " " << l ;
	return 0;
} 
