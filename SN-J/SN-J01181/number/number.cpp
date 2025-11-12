//SN-J01181 高思童 西安滨河学校
#include<bits/stdc++.h>
using namespace std;
string a;
int c[100000]={0};
int y[100000]={0};
int n=0;
int m=0;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>a;
	if (a.length()==1&&a=="1"||a=="2"||a=="3"||a=="4"||a=="5"||a=="6"||a=="7"||a=="8"||a=="9")
	{
		cout<<a;
	}
	for(int i=0;i<a.length();i++)
	{
		if (a[i]-'0'==0||a[i]-'0'==1||a[i]-'0'==2||a[i]-'0'==3||a[i]-'0'==4||a[i]-'0'==5||a[i]-'0'==6||a[i]-'0'==7||a[i]-'0'==8||a[i]-'0'==9)
		{
			c[n]=a[i]-'0';
			n++;
		}
	}
	sort(c,c+n,greater<int>());
	for(int i=0;i<n;i++)
	{
		cout<<c[i];
	}
	return 0;
 } 
