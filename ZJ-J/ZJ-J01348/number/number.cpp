#include <bits/stdc++.h>
using namespace std;
char a;
const int N=1e6+33;
int ar[N];
string s;
int cmp(int y, int z)
{
	return y>z;
}
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int x=1;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    {
    	if (s[i]>='0' && s[i]<='9')
    	{
    		ar[x]=s[i]-'0';
    		x++;
		}
	}
	sort (ar+1, ar+x+1, cmp);
	if (ar[1]==0)
	{
		cout<<0;
		return 0;
	}
	for (int i=1; i<x; i++)
	{
		cout<<ar[i];
	}
    return 0;
}
