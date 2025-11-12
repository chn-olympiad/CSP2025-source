#include <bits/stdc++.h>
using namespace std;
string s;
const int man=1e6;
int a[man];
int n;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<=l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[n]=s[i]-48;
			n++;
		}
	}
	sort(a,a+n+1,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
