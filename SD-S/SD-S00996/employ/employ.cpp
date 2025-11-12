#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int c[505];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	s = " " + s;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	if(n <= 10)
	{
		int p[15];
		for(int i = 1;i <= n;i++) p[i] = i;
		int ans = 0;
		do
		{
			int cnt = 0;
			int fcnt = 0; 
			for(int i = 1;i <= n;i++)
			{
//				cout << p[i] << " " << s[p[i]] << " " << c[p[i]] << endl;
				if(fcnt >= c[p[i]])
				{
//					cout << "X ";
					fcnt++;
				}
				else if(s[i] == '0')
				{
//					cout << "X ";
					fcnt++;
				}
				else
				{
//					cout << "O ";
					cnt++;
				}
			}
//			cout << cnt << endl;
			if(cnt >= m) ans++;
		}while(next_permutation(p + 1,p + n + 1));
		cout << ans << endl;
		return 0;
	}
	return 0;
}
/*
You should write "freopen" like this:
feropen("empoly.in",'w',stdin);
I want to show myself on the TV!
UID=1235038
*/
