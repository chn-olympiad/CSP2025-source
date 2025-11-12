#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=5e5+10;
int a[maxn];
map<int,bool> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	Ios();
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=0,o=0;
	mp[0]=1;
	for(int i=1;i<=n;i++)
	{
		o^=a[i];
		if(mp[o^k])
		{
			cnt++;
			mp.clear();
			mp[0]=1;
			o=0;
		}
		else mp[o]=1;
	}
	cout<<cnt;
	return 0;
}
//8:58 pretest passed(6)