#include<bits/stdc++.h>
using namespace std;

long long ans,xl = 998244353,cnt;
int n,sum,a[5001];
vector<int> v[5001];
int hx[5001];

void dfs(int z,int num,int big,int zt,int p)
{
	//cout << z << num << big << zt << p << endl;
	if(num >= 3 and zt == 0 and num > 2*big)
	{
		zt = 1;
		ans++;
	}
	if(p > n) return;
	dfs(z,num,big,zt,p+1);
	dfs(z,num+a[p],max(big,a[p]),0,p+1);
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if(sum != n)
	{
		//return 0;
		sort(a+1,a+n+1);
		dfs(0,0,0,0,1);
		cout << ans%xl;
	}
	else
	{
		for(int i = 2;i <= n;i++)
		{
			cnt = i;
			for(int j = 2;j * j <= cnt;j++)
			{
				while(cnt%j==0)
				{
					v[i].push_back(j);
					cnt/=2;
				}
			}
			v[i].push_back(cnt);
		}
		
		for(int i = 3;i <= n;i++)
		{
			cnt = 1;
			for(int j = n;j >= max(n-i+1,i+1);j--)
			{
				//cout << j << " " << (n-j+1) << "  ";
				for(int k = 0;k < v[j].size();k++) hx[v[j][k]]++;
				for(int k = 0;k < v[(n-j+1)].size();k++) hx[v[(n-j+1)][k]]--;
//				cnt = (cnt * j) % xl;
//				cnt = (cnt / (n-j+1)) % xl;
			}
			for(int j = 2;j <= n;j++)
			{
				while(hx[j] > 0)
				{
					cnt = (cnt*j) % xl;
					hx[j]--;
				}
			}
			//cout << i << " "  << cnt << endl;
			ans = (ans + cnt)%xl;
		}
		cout << ans;
	}
	return 0;
}
