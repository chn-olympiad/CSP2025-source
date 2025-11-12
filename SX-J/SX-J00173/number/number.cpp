#include<bits/stdc++.h>
using namespace std;
char a[100000001];
string s;
bool cmp(int x,int y)
{
	if(y>x)
	return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int l,n,i,m,x=0;
    cin>>s;
    l=s.size();
    for(i=0;i<=l;i++)
    {
     if(s[i]>='0'&&s[i]<='9')
     {
      x++;
      a[x]=s[i];

	 }
	}
	sort(a+1,a+x+1,cmp);
	for(i=1;i<=x;i++)
	{
     cout<<a[i];
	}

}