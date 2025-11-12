//60pts:O(n^2)判异或前缀和再贪心 
//空间：够的，1e6的struct 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+15;
int sum[N];
int a[N];
struct node
{
	int l,r;
};
vector<node>ans;
bool cmp(node a,node b)
{
	if(a.r!=b.r)
		return a.r<b.r;
	else
		return a.l<b.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1] xor a[i];
	}
	//[l,r]xor_sum = sum[l-1]^sum[r]
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
			//[i,j]
			int now = sum[i-1] xor sum[j];
			if(now==k)
			{
				ans.push_back({i,j});
			} 
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	int len = ans.size();
	int r = -1;
	long long cnt = 0;
	for(int i = 0;i<len;i++)
	{
		int nl = ans[i].l;
		int nr = ans[i].r;
//		cout<<nl<<" "<<nr<<"\n";
		if(nl>r)
		{
			cnt++;
			r = nr;
		}
	}
	cout<<cnt<<"\n";
	return 0;
 } 
