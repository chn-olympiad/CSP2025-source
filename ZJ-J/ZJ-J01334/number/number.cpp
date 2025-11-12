#include<bits/stdc++.h>
using namespace std;
const int slen=20;
int a[slen];
string s;
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>s;
  memset(a,0,sizeof(a));
  for(int i=0;i<s.size();i++)
  {
  	if(s[i]>='0'&&s[i]<='9')
  	{
  	  int h=s[i]-'0';
  	  a[h]++;
	}
  }
  for(int i=9;i>=0;i--)
  {
  	while(a[i]!=0)
  	{
  	  cout<<i;
  	  a[i]--;
	}
  }
  return 0;
}