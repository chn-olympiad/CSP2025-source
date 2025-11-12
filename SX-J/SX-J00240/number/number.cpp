#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll arr[1000005],ans;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
		{
			arr[i+1]=s[i]-'0';
			ans++;
		}
	sort(arr+1,arr+s.size()+1,cmp);
	for(int i=1;i<=ans;i++)	cout<<arr[i];
	return 0;
}