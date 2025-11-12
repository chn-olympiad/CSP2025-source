#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int l,sum;
int num[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	l=s.length();
	for(int i=0;i<l;i++)
	{
		char c=s[i];
		if(c>='0'&&c<='9')
		{
			num[i]=c-'0';
			sum++;
		}
	}
	sort(num,num+l,cmp);
	for(int i=0;i<sum;i++)
	{
		cout<<num[i]; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}  
