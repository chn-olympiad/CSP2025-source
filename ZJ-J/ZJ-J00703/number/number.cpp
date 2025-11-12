#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int dig[13],tot;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for(int i=0;i<=sizeof(a)-1;i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			dig[a[i]-'0']++;
			tot++;
		}
	}
	int t=9;
	
	while(tot)
	{
		if(dig[t]!=0) 
		{
			cout << t;
			dig[t]--;
			tot--;
		}
		else t--;
		
	}
	
	
	
	
	return 0;
 } 
