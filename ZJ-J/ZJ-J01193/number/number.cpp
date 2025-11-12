#include<bits/stdc++.h>
using namespace std;
int a[10];
int i,j;
string x;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>x;
for(i=0;i<x.size();i++)
  if(x[i]<='9'&&x[i]>='0')
    a[x[i]-'0']++;
for(i=9;i>=0;i--)
  for(j=1;j<=a[i];j++)
    printf("%d",i);
return 0;
}
