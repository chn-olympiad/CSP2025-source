#include<iostream>
#include<string>
using namespace std;
string s;
int tong[20];
int main()
{
	freopen(number.in,"r",stdin);
	freopen(number.out,"w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]=='0') tong[0]++;
		if(s[i]=='1') tong[1]++;
		if(s[i]=='2') tong[2]++;
		if(s[i]=='3') tong[3]++;
		if(s[i]=='4') tong[4]++;
		if(s[i]=='5') tong[5]++;
		if(s[i]=='6') tong[6]++;
		if(s[i]=='7') tong[7]++;
		if(s[i]=='8') tong[8]++;
		if(s[i]=='9') tong[9]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(;tong[i]>0;tong[i]--) cout<<i;
	}
	return 0;
}
