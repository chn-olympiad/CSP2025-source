//SN-J00329 zhangjiakang xi'an gaoxindiyizhongxue
#include<bits/stdc++.h>
//using ll=long long;
using namespace std;
const int maxn=1e6+10;
string s;
int tot=0;
int a[maxn];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto v:s)
	{
		if('0'<=v&&v<='9')
			a[++tot]=v-'0';
	}
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++)cout<<a[i];
	return 0;
}
