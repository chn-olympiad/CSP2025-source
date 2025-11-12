#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
string s;
int main()
{
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	cin>>s,n=s.size();
	for(int i=0;i<n;i++)if(s[i]>='0'&&s[i]<='9')m++,a[m]=s[i]-'0';
	sort(a+1,a+m+1);
	for(int i=m;i>0;i--)cout<<a[i];
	return 0;
}
