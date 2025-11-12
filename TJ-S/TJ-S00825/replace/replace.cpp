#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2],t[200005][2];
bool special(string s)
{
	int cnt=0;
	for(int i=0;i<s.length();i++)
		if(s[i]=='b')
			cnt++;
		else if(s[i]!='a')
			return false;
	return cnt==1; 
}
namespace baoli
{
	multiset<pair<long long,long long> > c;
	const long long p=1e16+7,k=71;
	inline long long Hash(string s)
	{
		long long ans=0;
		for(int i=0;i<s.length();i++)
			ans=(ans*k+s[i]-'a'+1)%p;
		return ans;
	}
	int main()
	{
		for(int i=1;i<=n;i++)
		{
			long long a=Hash(s[i][0]),b=Hash(s[i][1]);
			c.insert(make_pair(a,b));
		}
		for(int i=1;i<=q;i++)
		{
			if(t[i][0]==t[i][1]||t[i][0].length()!=t[i][1].length())
			{
				cout<<"0\n";
				continue;
			}
			int ll=0x3f3f3f3f,rr=-0x3f3f3f3f;
			for(int j=0;j<t[i][0].length();j++)
				if(t[i][0][j]!=t[i][1][j])
				{
					ll=min(ll,j);
					rr=max(rr,j);
				}
			int ans=0;
			for(int l=0;l<=ll;l++)
			{
				long long now0=0,now1=0;
				for(int j=l;j<rr;j++)
				{
					now0=(now0*k+t[i][0][j]-'a'+1)%p;
					now1=(now1*k+t[i][1][j]-'a'+1)%p;
				}
				for(int r=rr;r<t[i][0].size();r++)
				{
					now0=(now0*k+t[i][0][r]-'a'+1)%p;
					now1=(now1*k+t[i][1][r]-'a'+1)%p;
					ans+=c.count(make_pair(now0,now1));
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
};
namespace A
{
//	int ans[200005];
//	struct query
//	{
//		int x,y,id;
//		bool operator <(query other)
//		{
//			return x!=other.x?x<other.x:y<other.y;
//		}
//	};
//	vector<query> q[200005];
//	vector<int> x[200005],y[200005];
//	void main()
//	{
//		
//		for(int i=1;i<=q;i++)
//		{
//			if(t[i][0]==t[i][1]||t[i][0].length()!=t[i][1].length())
//			{
//				ans[i]=0;
//			}
//			else
//			{
//				int ll=0x3f3f3f3f,rr=-0x3f3f3f3f;
//				for(int j=0;j<t[i][0].length();j++)
//					if(t[i][0][j]!=t[i][1][j])
//					{
//						ll=min(ll,j);
//						rr=max(rr,j);
//					}
//				q[++cur].x=ll;
//				q[cur].y=t[i][0].length()-rr-1;
//				q[cur].id=i;
//			}
//		}
//		sort(q+1,q+cur+1);
//		
//	}
	void main()
	{
		//18:06 
		//我想我很有可能写不完了 
		//我不知道我该怎么活下去。 
	}
	//距离比赛结束还有 18min。
	//把每个模式串中第一个和最后一个不同的位置找出来，记为 l,r
	//对 s_{i,0,l~r} 和 s_{i,1,l~r} 分别哈希得到 h1,h2
	//称这对模式串的种类为二元组 (h1,h2)
	//如果两个模式串的种类相同，则当使用其中一个模式串的时候，有可能另一个模式串也可以使用
	//如果较短的一组模式串 s0 和 s1 都是较长的模式串的连续字串，那么说明如果可以用较短的一定可以用较长的
	//把这种依赖关系连边，把模式串组看成点，得到一个森林
	//这个模式串组的价值为其深度
	//把询问的第一个和最后一个不同的位置找出来，记为 l,r
	//同样哈希得到 h1,h2，可以使用类型为 (h1,h2) 的模式串，答案为其中价值最大的一个
	//然后该怎么做呢
	//如果有后人的话，能否告诉我我想得对不对呢...? 
	//预期得分 100+80+25+24=239，输 
};
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)
		cin>>t[i][0]>>t[i][1];
	bool flag=true;
	for(int i=1;i<=n;i++)
		flag&=special(s[i][0])&special(s[i][1]);
	for(int i=1;i<=q;i++)
		flag&=special(t[i][0])&special(t[i][1]);
	if(flag)
		A::main();
	else
		baoli::main();
	return 0;
}
