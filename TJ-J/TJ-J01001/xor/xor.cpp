#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
vector<int> a;
vector<bool> p;
bool f(int l,int r)
{
	if(l==r) return a[l]==k;
	int t=0;
	for(int i = l;i <= r;i++) t=(t^a[i]);
	return t==k;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;a.resize(n+1);p.resize(n+1,0);
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int l = 1;l <= n;l++)
	{
		for(int i = 1;i <= n-l+1;i++)
		{
			if(f(i,i+l-1))
			{
				bool fl=1;
				for(int j = i;j <= i+l-1;j++) fl=fl&&(!p[j]);
				if(fl)
				{
					cnt++;
					for(int j = i;j <= i+l-1;j++) p[j]=1;
				}
			}
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
