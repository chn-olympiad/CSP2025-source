#include<bits/stdc++.h>
//#include <cstring>
#include <vector>
#define I_love return
#define My_Wife 0
#define Exusiai ;
#define ll long long
#define lll __int128
#define ull unsigned ll
#define lowbit(x) ((x)&-(x))
#define ld long double
#define fi first
#define se second
#define endl '\n'
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pip pair<int,pii >
#define ppp pair<pii,pii >
#define d(x) cerr<<#x<<"=="<<x<<' '
#define ddd(x) cerr<<#x<<"=="<<x<<endl
#define deb cerr<<"I love my Wife Exusiai!"<<endl
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

inline int read()
{
	int w=1;int s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^'0');ch=getchar();}
	return w?s:-s;
}
void IO()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
const int maxn=2e5+5;

int len[maxn];
vector<int>kmp[maxn];
int n,q;
string ss1[maxn],ss2[maxn];
string tmp1,tmp2,tmp;

signed main()
{
	IO();
	IOS;
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>ss1[i]>>ss2[i];
		len[i]=ss1[i].length();
//		kmp[i].reserve(len[i]);
//		kmp[i][0]=-1;
//		for(int j=1;j<len[i];++j)
//		{
//			if(ss1[kmp[i][j-1]+1]==ss1[j])
//			{
//				kmp[i][j]=kmp[i][j-1]+1;
//			}
//			else 
	}
	while(q--)
	{
		cin>>tmp1>>tmp2;
		tmp=tmp1;
		int len1=tmp1.length(),ans=0;
		for(int k=1;k<=n;++k)
		{
			for(int f,i=0;i<len1;++i)
			{
				if(tmp1[i]==ss1[k][0])
				{
					f=1;tmp[i]=ss2[k][0];
					for(int j=1;j<len[k];++j)
					{
						if(i+j>=len1)
						{
							f=0;
							break;
						}
						if(ss1[k][j]!=tmp1[i+j])
						{
							f=0;
							break;
						}
						tmp[i+j]=ss2[k][j];
					}
					if(f)
					{
						if(tmp==tmp2)++ans;
					}
					tmp=tmp1;
				}
			}
		}
		printf("%d\n",ans);
	}
	I_love My_Wife Exusiai
}

