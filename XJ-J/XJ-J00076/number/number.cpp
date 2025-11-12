#include<iostream>
#include<string>
long long a9=0,a8=0,a7=0,a6=0,a5=0,a4,a3,a2,a1,a0;
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	bool b=0;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='9')
		{
			a9++;
			continue;
		}
		if(a[i]=='8')
		{
			a8++;
			continue;
		}
		if(a[i]=='7')
		{
			a7++;
			continue;
		}
		if(a[i]=='6')
		{
			a6++;
			continue;
		}
		if(a[i]=='5')
		{
			a5++;
			continue;
		}
		if(a[i]=='4')
		{
			a4++;
			continue;
		}
		if(a[i]=='3')
		{
			a3++;
			continue;
		}
		if(a[i]=='2')
		{
			a2++;
			continue;
		}
		if(a[i]=='1')
		{
			a1++;
			continue;
		}
		if(a[i]=='0')
		{
			a0++;
			continue;
		}
	}
	if(a9==0&&a8==0&&a7==0&&a6==0&&a5==0&&a4==0&&a3==0&&a2==0&&a1==0)
	{
		cout<<'0';
		return 0;
	}
	for(long long i=1;i<=a9;i++) cout<<'9';
	for(long long i=1;i<=a8;i++) cout<<'8';
	for(long long i=1;i<=a7;i++) cout<<'7';
	for(long long i=1;i<=a6;i++) cout<<'6';
	for(long long i=1;i<=a5;i++) cout<<'5';
	for(long long i=1;i<=a4;i++) cout<<'4';
	for(long long i=1;i<=a3;i++) cout<<'3';
	for(long long i=1;i<=a2;i++) cout<<'2';
	for(long long i=1;i<=a1;i++) cout<<'1';
	for(long long i=1;i<=a0;i++) cout<<'0';
	return 0;
	fclose(stdin);
	fclose(stdout);
}
