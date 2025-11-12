#include<bits/stdc++.h>
using namespace std;
const int IMF=1e6+10;
int ans[IMF];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a;
	cin >> a;
	long long total=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='1' || a[i]=='2' || a[i]=='3' || a[i]=='4' || a[i]=='5' || a[i]=='6' || a[i]=='7' || a[i]=='8' || a[i]=='9' || a[i]=='0')
		{
			total++;
			ans[total]=a[i];
		}
	}
	sort(ans+1,ans+total+1);
	for(int i=total;i>=1;i--)
	{
		cout << ans[i]-48;
	}
	return 0;
}
