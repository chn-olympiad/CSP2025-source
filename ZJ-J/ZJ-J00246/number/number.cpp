#include<bits/stdc++.h>
using namespace std;
string s;
int a[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		if (s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
		if (a[i]>0)
		{
			for(int j=1;j<=a[i];j++) cout<<i;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
