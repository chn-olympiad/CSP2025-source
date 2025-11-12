#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int l=a.size(),nl=l,sum=0,nx=0;
	for(int i=0;i<l;i++)
	{
		if(a[i]=='1') cout<<"1";
		if(a[i]=='2') cout<<"2";
		if(a[i]=='3') cout<<"3";
		if(a[i]=='4') cout<<"4";
		if(a[i]=='5') cout<<"5";
		if(a[i]=='6') cout<<"6";
		if(a[i]=='7') cout<<"7";
		if(a[i]=='8') cout<<"8";
		if(a[i]=='9') cout<<"9";
		else if(l>=2)
		{
			if(a[i]>='0'&&a[i]<='9') a[i]-=48;
			if(a[i]%10==0) cout<<a[i];
			if(a[i]>='a'&&a[i]<='z')
			{
				nl--;
				if(nl==l)
				{
					cout<<a[i];
				}
			}
		}
	}
	return 0;
}
