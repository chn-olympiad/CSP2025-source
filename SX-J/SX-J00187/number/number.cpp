#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int cmp(int a,int b)
{
	return a>b;
}
int main ()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
string s;
long long q=0,x=0,y=1;
cin>>s;
for(int i=0;i<=s.size()-1;i++)
{
if(s[i]<=57&&s[i]>=48){

q++;
a[q]=s[i]-48;
}
}
sort(a+1,a+q+1,cmp);
for(int j=1;j<=q;j++)
{
	cout<<a[j];
}
	return 0;
}
