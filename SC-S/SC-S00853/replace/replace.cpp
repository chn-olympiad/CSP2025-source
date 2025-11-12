#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define ull unsigned long long

const int N = 1e4+15,base = 131;

ull hasha[N],hashb[N];
string stra[N],strb[N];
int n,m;

inline ull gethash(string s)
{
	ull v = 0;
	for(auto i:s)
	{
		v = v*131+i;
	}
	return v;
}

inline ull qpow(int p)
{
	ull ans = 1,a = 131;
	for(int b = p;b;b>>=1)
	{
		if(b&1)ans = ans*a;
		a = a*a;
	}
	return ans;
}

ull hapos[N],hbpos[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>stra[i]>>strb[i];
		hasha[i] = gethash(stra[i]),
		hashb[i] = gethash(strb[i]);
//		cout<<"?? "<<hasha[i]*qpow(2)<<' '<<hashb[i]*qpow(2)<<endl;
	}
	
	
	string s1,s2;
	while(m--)
	{
		cin>>s1>>s2;
		int l = 0x3f3f3f3f3f3f3f3f,r = -1;
		int len = s1.size();
		int ans = 0;
		for(int i = len;i<len;i++)
		{
			if(s1[i] != s2[i])l = min(l,i),r = max(r,i);
			hapos[i] = (i == 0?0:hapos[i-1])*131+s1[i];
			hbpos[i] = (i == 0?0:hbpos[i-1])*131+s2[i];
		}
//		cout<<l<<' '<<r<<endl;
//		cout<<hapos[3]-hapos[1]<<endl;
		ull vva = 0,vvb = 0;
		for(int i = 0;i<len;i++)
		{
			if(i > l)
			{
				vva = vva*131+s1[i],vvb = vvb*131+s2[i];
				break;
			}
			for(int j = 1;j<=n;j++)
			{
				if(i+(int)stra[j].size()-1 >= len || i+(int)stra[j].size()-1 < r)continue;
//				cout<<"~ "<<i<<endl;
//				cout<<"!! "<<hapos[i+(int)stra[j].size()-1]-(i==0?0ull:hapos[i])<<' '<<hbpos[i+(int)stra[j].size()-1]-(i==0?0ull:hbpos[i])<<endl;
				if(hapos[i+(int)stra[j].size()-1]-vva*qpow(i) == hasha[j]*qpow(i) &&
				   hbpos[i+(int)stra[j].size()-1]-vvb*qpow(i) == hashb[j]*qpow(i))
				{
					ans++;
				}
			}
			vva = vva*131+s1[i],vvb = vvb*131+s2[i];
		}
		cout<<ans<<endl;
	}
	
	return 0;
 }
