#include<bits/stdc++.h>
using namespace std;
string s;
int i,j,len,n,a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			j++;a[j]=s[i]-48;
		}
	}
	n=j;
	sort(a+1,a+1+n);
	for(i=n;i>=1;i--)
		cout<<a[i];
}
