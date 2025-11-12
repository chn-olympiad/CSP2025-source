#include<bits/stdc++.h>
using namespace std;
int b[20000005]={0};
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,k;
	string a;
	cin>>a;
	int s=1;
	for(i=0;i<=a.size();i++)
	{
		if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0')
		{
			b[s]=a[i]-48;
			s++;
			
		}
	}
	sort(b+1,b+s,cmp);
	for(i=1;i<=s-1;i++)
	{
		cout<<b[i]; 
	}
	return 0;
}
