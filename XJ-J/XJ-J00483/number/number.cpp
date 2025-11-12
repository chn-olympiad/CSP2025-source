#include<bits/stdc++.h>
using namespace std;
long long int n,shuzi[1000009],k=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	long long int x,i;
	string s; 
	cin>>s;
	n=s.size();
	for(i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			if(s[i]=='0')
			shuzi[++k]=0;
			if(s[i]=='1')
			shuzi[++k]=1;
			if(s[i]=='2')
			shuzi[++k]=2;
			if(s[i]=='3')
			shuzi[++k]=3;
			if(s[i]=='4')
			shuzi[++k]=4;
			if(s[i]=='5')
			shuzi[++k]=5;
			if(s[i]=='6')
			shuzi[++k]=6;
			if(s[i]=='7')
			shuzi[++k]=7;
			if(s[i]=='8')
			shuzi[++k]=8;
			if(s[i]=='9')
			shuzi[++k]=9;
		}
	}
	sort(shuzi+1,shuzi+1+k);
	
	for(i=k;i>=1;i--)
	cout<<shuzi[i];

	return 0;
}
 
