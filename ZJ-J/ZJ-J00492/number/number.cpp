#include<bits/stdc++.h>
#define ll long long
#define ac ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
ll a[11];
string s;
bool f=0;
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  ac;
  cin>>s;
  for(ll i=0;i<s.size();i++)
  {
  	if(s[i]<='9' && s[i]>='0') a[s[i]-'0']++;
  }
  for(ll i=9;i>=0;i--)
  {
  	if(i==0 && f==0) cout<<0;
  	else
  	{
  	  for(ll j=1;j<=a[i];j++)
  	  {
  	  	f=1;
  	  	cout<<i;
	  }
	}
  }
  return 0;
}
