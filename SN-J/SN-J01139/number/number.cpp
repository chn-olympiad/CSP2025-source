#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string s;
char r[N];
int ant;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			ant++;
			r[ant] = s[i];
		}
	}
	sort(r+1,r+1+ant);
	for(int i = ant;i>=1;i--)
	{
		cout << r[i];
	}
}
