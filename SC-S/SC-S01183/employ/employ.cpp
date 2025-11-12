#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string s;
int a[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m>>s;
	int len=s.size();
	bool flag_A=1;
	for(int i=0;i<len;i++)
	{
		if(s[i]!='1')
		{
			flag_A=0;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(flag_A)
	{
		cout<<n;
		break;
	}
	return 0;
}
