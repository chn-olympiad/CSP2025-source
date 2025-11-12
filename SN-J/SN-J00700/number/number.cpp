// SN-J00700 niujunxiang
#include<bits/stdc++.h>
using namespace std;
string aa;
char bb[1000005];
long long a[11],si,b,c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>bb;
	si=aa.size();
	int ii=0;
	for(int i=0;i<si;i++)
	{
		if(aa[i]>='0'&&aa[i]<='9')
		{
			a[ii]=aa[i]-'0';
			ii++;
		}
	}
	sort(a,a+ii);
	for(int i=ii-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
