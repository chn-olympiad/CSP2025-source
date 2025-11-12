#include<bits/stdc++.h>
using namespace std;
int a[1000005],k;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9) a[++k]=s[i]-'0';

	}
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--) cout<<a[i];
	return 0;
}
