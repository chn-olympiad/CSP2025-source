#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>

const int N =1e5+15;

struct Node{
	int a,b,c,maxv;
}arr[N];
int T,n;

vector<int> va,vb,vc;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		va.clear(),vb.clear(),vc.clear();
		va.shrink_to_fit(),vb.shrink_to_fit(),vc.shrink_to_fit();
		cin>>n;
		int cnta = 0,cntb = 0,cntc = 0,ans = 0;
		for(int i = 1;i<=n;i++)
		{
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
			int maxn = max({arr[i].a,arr[i].b,arr[i].c}),
				minn = min({arr[i].a,arr[i].b,arr[i].c}),
				v = arr[i].a^arr[i].b^arr[i].c;
			arr[i].maxv = maxn;
			ans += arr[i].maxv;
			
			if(arr[i].a == maxn)
			{
				va.push_back(arr[i].a - (v^maxn^minn));
				cnta++;
			}
			else if(arr[i].b == maxn)
			{
				vb.push_back(arr[i].b - (v^maxn^minn));
				cntb++;
			}
			else
			{
				vc.push_back(arr[i].c - (v^maxn^minn));
				cntc++;
			}
		}
		
		
		if(cnta > n/2)
		{
			sort(va.begin(),va.end());
			for(int i = 0;i<cnta-n/2;i++)
			{
				ans -= va[i];
			}
		}
		if(cntb > n/2)
		{
			sort(vb.begin(),vb.end());
			for(int i = 0;i<cntb-n/2;i++)
			{
				ans -= vb[i];
			}
		}
		if(cntc > n/2)
		{
			sort(vc.begin(),vc.end());
			for(int i = 0;i<cntc-n/2;i++)
			{
				ans -= vc[i];
			}
		}
		
		cout<<ans<<'\n';
	}

	return 0;
 }
