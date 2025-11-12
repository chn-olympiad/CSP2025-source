#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int x,y;
	cin>>x>>y;
	int n = x*y;
	int a;
	cin>>a;
	vector<int> l;
	l.push_back(a);
	for(int i = 0;i<n-1;i++)
	{
		int la;
		cin>>la;
		l.push_back(la);
	}
	sort(l.begin(),l.end());
	int st = 0;
	int m = 0;
	for(int i = n-1;i>=0;i--)
	{
		if(l[i] == a)
		{
			st = m;
			break;
		}
		m++;
	}
	int li = st/x+1;
	int hi = 0,h = st%x;
	if(li%2 == 0)
	{
		hi = x-h;
	}
	else
	{
		hi = h+1;
	}
	cout<<li<<" "<<hi;
	
	return 0;
}
