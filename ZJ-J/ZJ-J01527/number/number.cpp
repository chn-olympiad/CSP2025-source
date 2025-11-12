#include<bits/stdc++.h>
#define int long long
using namespace std;

string s;
int a[1000005];
bool cmp(int x,int y) {return x>y;}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=1;
	for(int i=0;i<=1000005;i++) a[i]=-1;
	for(int i=0;i<s.size();i++)
	{ 	 	
		if(s[i]>='0' && s[i]<='9') a[j]=s[i]-'0',j++;
	}
	sort(a+1,a+1+s.size(),cmp);
	for(int i=1;i<=s.size();i++)
	{
		if(a[i]!=-1) cout<<a[i];
	}
	//#Shang4Shan3Ruo6Shui4
	return 0;


}

