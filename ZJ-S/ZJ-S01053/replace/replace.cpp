#include<bits/stdc++.h>
#define int long long
#define f(i,x,y) for(register int i=x;i<=y;++i)
#define d(i,x,y) for(register int i=x;i>=y;--i)
using namespace std;
int n,q;
string s1[200001],s2[200001],t1[200001],t2[200001];
map<char,vector<int> >c;
int L1,L2;
int up1[200001],dn1[200001],up2[200001],dn2[200001],upt1[200001],dnt1[200001],upt2[200001],dnt2[200001];
void solve1()
{
    f(i,1,q)
    {
    	if(t1[i].size()!=t2[i].size())
    	{
    		cout<<0<<endl;
    		continue;
		}
		int ans=0;
		f(k,0,t1[i].size()-1)
		    if(c[t1[i][k]].size())
		    {
		    	f(j,0,c[t1[i][k]].size()-1)
		    	{
		    		string y1=s1[c[t1[i][k]][j]];
		    		string y2=s2[c[t1[i][k]][j]];
		    		string lm=t1[i].substr(k,y1.size());
		    		if(lm!=y1)continue;
		    		string ll=t1[i].substr(0,k),lr=t1[i].substr(k+y1.size(),t1[i].size()-k-y1.size());
		    		if(ll+y2+lr==t2[i])ans++;
				}
			}
		cout<<ans<<endl;
	}		
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    f(i,1,n)
	{
		cin>>s1[i]>>s2[i];
		c[s1[i][0]].push_back(i);
		L1+=s1[i].size()+s2[i].size();
	}
    f(i,1,q)cin>>t1[i]>>t2[i],L2+=t1[i].size()+t2[i].size();
    if(n<=1000&&q<=1000&&L1<=2000&&L2<=2000||q==1&&n>=10000)solve1();
    f(i,1,n)
    {
    	int b1=s1[i].find('b')+1,b2=s2[i].find('b')+1,en1=s1[i].size(),en2=s2[i].size();
    	up1[i]=b1-1,up2[i]=b2-1;
    	dn1[i]=en1-b1,dn2[i]=en2-b2;
	}
    f(i,1,q)
    {
    	int b1=t1[i].find('b')+1,b2=t2[i].find('b')+1,en1=t1[i].size(),en2=t2[i].size();
    	upt1[i]=b1-1,upt2[i]=b2-1;
    	dnt1[i]=en1-b1,dnt2[i]=en2-b2;
	}
	f(i,1,q)
	{
		int ans=0;
	    f(j,1,n)
	    	if(upt1[i]>=up1[j]&&upt2[i]>=up2[j]&&dnt1[i]>=dn1[j]&&dnt2[i]>=dn2[j]&&upt1[i]-upt2[i]==up1[j]-up2[j]&&dnt1[i]-dnt2[i]==dn1[j]-dn2[j])ans++;		
	    cout<<ans<<endl;
	}
    return 0;
}