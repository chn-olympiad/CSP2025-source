#include <bits/stdc++.h>
using namespace std;
string y;
int a[1000000+10],n=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>y;
	int len=y.size();
	for(int i=0;i<=len;i++)
	{
		if(y[i]=='1'||y[i]=='2'||y[i]=='3'||y[i]=='4'||y[i]=='5'||y[i]=='6'||y[i]=='7'||y[i]=='8'||y[i]=='9'||y[i]=='0')
		{
			a[n]=y[i]%48;
			n++;
		}			
	}	
	sort(a+1,a+1+n);
	for(int i=n;i>=2;i--) cout<<a[i];
	return 0;
} 
