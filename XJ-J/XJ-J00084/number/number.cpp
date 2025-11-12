#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len=s.size(),k=0;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++k]=s[i]-'0';
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--)
		cout <<a[i];
	cout <<'\n';
	return 0;
}
 
