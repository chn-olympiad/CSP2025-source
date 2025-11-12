#include<bits/stdc++.h>
using namespace std;
const int base=29,mod=1000000007;
int n,q,l[200010],mx;
long long pw[5000010],h[200010],H[5000010];
string t1,t2,s1[200010],s2[200010];
vector<int> nxt[200010];
inline long long get_hash(string st)
{
	long long s=0;int l=st.size();
	for(int i=1;i<=l-1;i++) s=(s*base%mod+st[i]-'a'+1)%mod;
	return s;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;pw[0]=1;
	for(int i=1;i<=5000002;i++) pw[i]=pw[i-1]*base%mod; 
	for(int i=1;i<=n;i++) 
	{
		cin>>s1[i]>>s2[i];l[i]=s1[i].size();mx=max(mx,l[i]);s1[i]=' '+s1[i];s2[i]=' '+s2[i];
		nxt[i].emplace_back(0);nxt[i].emplace_back(0);
		for(int j=2,k=0;j<=l[i];j++)
		{
			while(k&&s1[i][k+1]!=s1[i][j]) k=nxt[i][k];
			if(s1[i][k+1]==s1[i][j]) k++;
			nxt[i].emplace_back(k);
		}
		h[i]=get_hash(s2[i]); 
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;int l1=t1.size(),l2=t2.size();if(l1!=l2) {puts("0");continue;}
		t1=' '+t1;t2=' '+t2;int L=l1,R=0;long long ans=0;
		for(int j=1;j<=l1;j++) if(t1[j]!=t2[j]) {L=j;break;}
		for(int j=l1;j>=1;j--) if(t1[j]!=t2[j]) {R=j;break;}  
		if(R-L+1>mx) {puts("0");continue;}
		for(int j=1;j<=l1;j++) H[j]=(H[j-1]*base%mod+(t2[j]-'a'+1))%mod;
		for(int j=1;j<=n;j++)
		{
			if(l[j]<R-L+1) continue;if(l[j]>l1) continue;
			for(int ii=max(L-l[j],0),jj=0;ii<=min(R+l[j],l1);ii++)
			{
				while(jj&&s1[j][jj+1]!=t1[ii]) jj=nxt[j][jj];
				if(s1[j][jj+1]==t1[ii]) jj++;
				if(jj==l[j])
				{
					if(ii-l[j]+1<=L&&ii-l[j]+1>=0&&ii>=R)
					{
						long long h1=h[j];
						long long h2=(H[ii]-H[(ii-l[j]+1)-1]*pw[l[j]]%mod+mod)%mod;
						if(h1==h2) ans++;
					}
					jj=nxt[j][jj];
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//50
