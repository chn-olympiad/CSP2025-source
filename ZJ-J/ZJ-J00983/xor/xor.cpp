#include<bits/stdc++.h>
#define int long long
#define Ms(shuzu,val) memset(shuzu,val,sizeof(shuzu))
#define Exit(str,val) {cout<<str<<endl;return val;}
#define Ls (rt<<1)
#define Rs (rt<<1|1)
#define mid (((l)+(r))>>1)
using namespace std;
const int N=5e5+5;
int a[N],s[N];
struct TRee{
	struct tree{
		int val,tag;
	}tr[N<<2];
	void Push_Up(int rt){tr[rt].val=tr[Ls].val+tr[Rs].val;}
	void Push_Down(int rt,int l,int r)
	{
		if(!tr[rt].tag) return;
		tr[Ls].val=mid-l+1;
		tr[Rs].val=r-mid;
		tr[Ls].tag=tr[Rs].tag=1;
		tr[rt].tag=0;
	}
	void Update(int rt,int l,int r,int x,int y)
	{
		if(x<=l&&r<=y){tr[rt]={r-l+1,1};return;}
		Push_Down(rt,l,r);
		if(x<=mid) Update(Ls,l,mid,x,y);
		if(y>mid) Update(Rs,mid+1,r,x,y);
		Push_Up(rt);
	}
	int Query(int rt,int l,int r,int x,int y)
	{
		if(x<=l&&r<=y) return tr[rt].val;
		Push_Down(rt,l,r);int ans=0;
		if(x<=mid) ans+=Query(Ls,l,mid,x,y);
		if(y>mid) ans+=Query(Rs,mid+1,r,x,y);
		return ans;
	}
}t;//wei hu qu jian he
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]^a[i];
//	sort(s+1,s+n+1);
	vector<pair<int,int> >vec;
//	for(int i=1;i<=n;i++) cout<<s[i]<<" ";
//	for(int i=1;i<=n;i++)
//	{
//		int x=s0[i]^k;
//		int pos=upper_bound(s+i+1,s+n+1,x)-s-1;
//		if(s[pos]==x) vec.push_back({i+1,pos});
//		cout<<i<<" "<<pos<<endl;
//	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((s[i-1]^s[j])==k){vec.push_back({i,j});break;}
	sort(vec.begin(),vec.end(),[&](pair<int,int>x,pair<int,int>y){
		int x0=x.second-x.first,y0=y.second-y.first;
		if(x0==y0) return x.first>y.first;
		return x0<y0;
	});int ans=0;
//	for(auto x:vec) cout<<1<<" "<<x.first<<" "<<x.second<<endl;
//	cout<<"-------------------------------"<<endl;
	for(auto x:vec)
	{
		int s=t.Query(1,1,n,x.first,x.second);
		if(s!=0) continue;
//		cout<<2<<" "<<x.first<<" "<<x.second<<endl;
		ans++,t.Update(1,1,n,x.first,x.second);
	}
//	for(auto x:vec) cout<<x.first<<" "<<x.second<<endl;
	cout<<ans<<endl;
	return 0;
}
/*
4 0
2 1 0 3
*/
/*
That's the end of a story.
我舍弃了一切，就换来这样一个结果？
这不是我所想看到的。
By,OI.Hello,whk.
AFOed. 2025.11.01 MorningStarCzy
*/