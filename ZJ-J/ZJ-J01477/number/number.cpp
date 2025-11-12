#include<bits/stdc++.h>
using namespace std;
const int maxn=128;
int f[maxn],l;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	  if(s[i]>='0'&&s[i]<='9')
	    f[s[i]]++;
	for(int i='9';i>='0';i--)
	  for(int j=1;j<=f[i];j++)
	    putchar(i);
	return 0;
}
