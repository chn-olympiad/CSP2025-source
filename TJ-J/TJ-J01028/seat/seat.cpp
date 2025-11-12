#include <bits/stdc++.h> 

using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int total = n*m;
	vector<int> a(total);
	for(int i = 0;i<total;i++)
	{
		cin >> a[i];
	}
	int res = a[0];
	vector<int> b = a;
	sort(b.begin(),b.end(),greater<int>());
	int k = 0;
	for(int i = 0;i<total;++i)
	{
		if(b[i] = res)
		{
			k = i+1;
			break;
		}
	}
	int c = (k-1) / n+1;
	int pos = (k-1) % n;
	int r = 0;
	if(c%2 == 1)
	{
		r = pos+1;
	}
	else 
	{
		r = n - pos;
	}
	cout << c << ' ' << r+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
