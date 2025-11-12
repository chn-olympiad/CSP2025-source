#include<bits/stdc++.h> 
using namespace std;
int t,a[100005];
int main()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	string a;
	int i,flog=0,l;
	l=a.size();
	cin>>a;
	for(i=0;i<l;i++)
	{
		if(i=='0' or i=='1' or i=='2' or i=='3' or i=='4' or i=='5' or i=='6' or i=='7' or i=='8' or i=='9')
        {
			flog=1;
		}
	}
	if(flog==1)
	{
		if(a[i]<a[i+1])
		{
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
	}
	cout<<a[i];
	return 0;
}
