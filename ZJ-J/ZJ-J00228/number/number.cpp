#include<bits/stdc++.h>
using namespace std;
int a[1145141];
string s;
int main()
{
	int lens,i,j,k=0,t;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	lens=s.size();
	for(i=0;i<lens;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+k);
	for(i=k-1;i>=0;i--) cout<<a[i];
}
