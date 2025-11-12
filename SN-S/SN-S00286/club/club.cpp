#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N][4];
int n;
int ans = -1;
int mxsum[N];
void dfs(int now,int cnta,int cntb,int cntc,int sum)
{
	if(sum+mxsum[n]-mxsum[now-1]<=ans) return ;//¼ôÖ¦1 ¿É¹ýn=30 
    if(now>n)
    {
        ans=max(ans,sum);
        return ;
    }
    bool flaga,flagb,flagc;
    flaga=flagb=flagc=1;
    if(cnta>=n/2) flaga = 0;
    if(cntb>=n/2) flagb = 0;
    if(cntc>=n/2) flagc = 0;
    if(flaga) dfs(now+1,cnta+1,cntb,cntc,sum+a[now][1]);
    if(flagb) dfs(now+1,cnta,cntb+1,cntc,sum+a[now][2]);
    if(flagc) dfs(now+1,cnta,cntb,cntc+1,sum+a[now][3]);
}
bool cmp(int a,int b)
{
	return a>b;
}
void f()
{
	vector<int>s;
	for(int i = 1;i<=n;i++) s.push_back(a[i][1]);
	int len = s.size();
	sort(s.begin(),s.end(),cmp);
	int cnt = 0;
	for(int i = 0;i<len/2;i++) cnt+=s[i];
	cout<<cnt<<"\n";
}
inline void solve()
{
    cin>>n;
    memset(a,0,sizeof a);
    memset(mxsum,0,sizeof mxsum);
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        mxsum[i]=mxsum[i-1]+max({a[i][1],a[i][2],a[i][3]});
    }
    if(n>30) 
	{
		f(); 
		return ;
	}
    //O(3^n)->dfs
    ans=-1;
    dfs(1,0,0,0,0);
    cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
