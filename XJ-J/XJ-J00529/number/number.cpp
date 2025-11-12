#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int ans[N],i=1;
char s;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	while(cin>>s)
	{
		if(s>='0'&&s<='9')
		{
			ans[i]=s-'0';
			i++;
		}
	}
	sort(ans+1,ans+i+1,cmp);
	for(int j=1;j<i;j++)
	{
		cout<<ans[j];
	}
	return 0;
} 
