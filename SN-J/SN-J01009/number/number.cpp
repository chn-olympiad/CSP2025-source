#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int a[100010];
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'||s[i]>='9'){
			a[++i]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		 
		cout<<a[i];
	}
	return 0;
}
