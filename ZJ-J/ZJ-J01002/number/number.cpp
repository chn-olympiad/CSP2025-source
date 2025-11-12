#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,str="";
	cin >> s;
	int sum0=0,sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,sum7=0,sum8=0,sum9=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			sum0++;
		}
		if(s[i]=='1')
		{
			sum1++;
		}
		if(s[i]=='2')
		{
			sum2++;
		}
		if(s[i]=='3')
		{
			sum3++;
		}
		if(s[i]=='4')
		{
			sum4++;
		}
		if(s[i]=='5')
		{
			sum5++;
		}
		if(s[i]=='6')
		{
			sum6++;
		}
		if(s[i]=='7')
		{
			sum7++;
		}
		if(s[i]=='8')
		{
			sum8++;
		}
		if(s[i]=='9')
		{
			sum9++;
		}
	}
	while(sum9--) cout << "9";
	while(sum8--) cout << "8";
	while(sum7--) cout << "7";
	while(sum6--) cout << "6";
	while(sum5--) cout << "5";
	while(sum4--) cout << "4";
	while(sum3--) cout << "3";
	while(sum2--) cout << "2";
	while(sum1--) cout << "1";
	while(sum0--) cout << "0";
}
