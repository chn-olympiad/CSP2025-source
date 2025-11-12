#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
char s[N];
int n=1,ans;
long long int a[N];
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>s;
  for(int i=0;i<strlen(s);i++)
  {
  	int now=int(s[i]);
  	if(now>=48&&now<=57)
  	{
  	  a[n]=now-48;
  	  n++;
	}
  }
  n--;
  sort(a+1,a+n+1);
  for(int i=n;i>0;i--) cout<<a[i];
  //cout<<"   "<<n;
  return 0;
}
