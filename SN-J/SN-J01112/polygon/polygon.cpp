#include <iostream>
#include <string>
using namespace std;

long long inlist[100005];

string totwo(long long wantchange)
{
	string out = "";
	while(wantchange)
	{
		out += char('0' + wantchange % 2);
		wantchange /= 2;
	}
	return out;
}

bool solve(string usenum)
{
	long long max = -1e9;
	long long sum = 0;
	long long length_oof = usenum.length();
	for (int j = 0; j < length_oof; ++j)
	{
		if (usenum[j] == '1')
		{
			sum += inlist[j];
			if(inlist[j] > max)
			{
				max = inlist[j];
			}
		}
	}
	max << 1;
	return sum > 2 * max;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	long long n;
	cin >> n;
	long long Max = 1 << n;
	
	for (int j = 0; j < n; ++j)
	{
		cin >> inlist[j];
	}
	
	long long ans = 0;
	for (long long j = 1; j < Max; ++j)
	{
		string upp = totwo(j);
		if (solve(upp))
		{
			ans++;
		}
	}
	cout << ans % 998244353;
	return 0;
} 
