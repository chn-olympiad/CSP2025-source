#include <bits/stdc++.h>
using namespace std;
string s;
string a;
string b;
int t=0,n=0,z=0,c=0;
int main(){
//	number.in,"r",stdin;
//	number.out,"w",stdout;
	cin>>s;
	while(z<s.length()+1)
	{
		if(s[t]<9 && s[t]>0)
		{
			a[n]==s[t];
			n++;
			t++;
		}
		else
		{
			t++;
		}
		z++;
	}
	t==0;
	while(t<a.length()+1)
	{
		while(c<a.length()+1)
		{
			if(a[c]>a[c+1])
			{
				b[t]==a[c];
				a[c+1]==-1;
			}
			else if(a[c+1]>a[c])
			{
				b[t]==a[c+1];
				a[c]==-1;
			}
			c++;
		}
		t++;
	}
	return 0;
}