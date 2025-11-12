#include<bits/stdc++.h>
using namespace std;
string s;
int q[1000005];
long long k;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			k++;
			q[k]=int(s[i]-'0');
		}
	}
	sort(q+1,q+k+1,cmp);
	for(long long i=1;i<=k;i++)
		printf("%d",q[i]);
				
	return 0;
}

