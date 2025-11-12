#include<bits/stdc++.h>
using namespace std;
string a;
long long w[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long b=a.length();
	for(long long i=0;i<b;i++)
	{
		if(a[i]=='0')w[0]+=1;
		else if(a[i]=='1')w[1]+=1;
		else if(a[i]=='2')w[2]+=1;
		else if(a[i]=='3')w[3]+=1;
		else if(a[i]=='4')w[4]+=1;
		else if(a[i]=='5')w[5]+=1;
		else if(a[i]=='6')w[6]+=1;
		else if(a[i]=='7')w[7]+=1;
		else if(a[i]=='8')w[8]+=1;
		else if(a[i]=='9')w[9]+=1;				
	}
	for(int o=9;o>=0;o--)
	{
		for(long long r=0;r<w[o];r++)
		{
			cout<<'9'-48-(9-o);	
		}
	}
	return 0;
}
