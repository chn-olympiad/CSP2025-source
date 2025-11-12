#include<bits/stdc++.h>
#define inf 1000005
using namespace std;
string a;
int b[inf];
int cnt;
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(int(a[i])>=48 && int(a[i])<=57)
		{
			cnt++;
			b[cnt]=int(a[i])-48;
		}
	}
	sort(b+1,b+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<b[i];
	return 0;
}
