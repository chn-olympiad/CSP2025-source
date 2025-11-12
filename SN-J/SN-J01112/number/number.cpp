#include <iostream>
#include <string>
using namespace std;

long long cnt[15] = {0};

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string in;
	cin >> in;
	long long length_in = in.length();
	for (long long j = 0; j < length_in; ++j)
	{
		char t = in[j];
		if (t >= '0' && t <= '9')
		{
			cnt[t - '0']++;
		}
	}
	
	for (int j = 9; j >= 0; --j)
	{
		while (cnt[j] > 0)
		{
			cout << j;
			cnt[j]--;
		}
	}
	
	return 0;
}
