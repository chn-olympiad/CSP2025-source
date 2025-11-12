#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
class encpass
{
	private:
		ll ctw[105]={11,21,31,41,51,61,71,81,91,10,11,12,13,14,15,16,17,18,19,10};
		ll cto[10]={1,5,7,1,1,1};
	public: 
		void tenc(string s)
		{
			for (int i=1;i<=s.length()-1;i+=2)
			{
				s[i-1]+=ctw[(i-1)%20];
				s[i]+=ctw[(i-1)%20];
			}
			for (int i=0;i<=s.length()-1;i++)
			{
				s[i]+=cto[i%6];
			}
			cout << s;
		}
};
string s;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	encpass nodenc;
	cin >> s;
	nodenc.tenc(s);
} 
