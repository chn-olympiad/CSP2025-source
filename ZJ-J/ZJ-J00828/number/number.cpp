#include<bits/stdc++.h>
using namespace std;
int n,m,a[20],al;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	cerr<<"u\n";
	cin>>s;n=s.length();
	for(int i=0;i<n;i++)if('0'<=s[i]&&s[i]<='9')a[s[i]-'0']++;
	for(int i=9;i>=0;i--)for(int j=1;j<=a[i];j++)putchar(i+'0');
	return 0;
}
