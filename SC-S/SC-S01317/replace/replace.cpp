#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
int n,q;
struct node{
	string s,t;
	int len,id;
}a[202020],b[202020];
const int B=300000;
int ax,bx;
const int base=233,mod=998244353,base2=517;
ull b1[5000005];
int b2[5000005],ans[500500];
pair<ull,int> hs[5000005],ht[5000005],a1[5005000],a2[5005000];
map<pair<pair<ull,int>,pair<ull,int> >,int > tong;
//[1,ax-1] ,[ax,n]
pair<ull,int> calc(int l,int r)
{
	return {hs[r].first-hs[l-1].first*b1[r-l+1],((hs[r].second-hs[l-1].second*b2[r-l+1]%mod)%mod+mod)%mod};
}
pair<ull,int> calc2(int l,int r)
{
	return {ht[r].first-ht[l-1].first*b1[r-l+1],((ht[r].second-ht[l-1].second*b2[r-l+1]%mod)%mod+mod)%mod};
}
bool cmp(node a,node b) {return a.len>b.len;}
main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].t,a[i].len=a[i].s.size(),a[i].s="!"+a[i].s,a[i].t="!"+a[i].t;
	for(int i=1;i<=q;i++) cin>>b[i].s>>b[i].t,b[i].len=b[i].s.size(),b[i].id=i,b[i].s="!"+b[i].s,b[i].t="!"+b[i].t;
	sort(a+1,a+n+1,cmp),sort(b+1,b+n+1,cmp);
	ax=bx=n+1;
	for(int i=1;i<=n;i++) if(a[i].len>B) {ax=i;break;}
	for(int i=1;i<=n;i++) if(b[i].len>B) {bx=i;break;}
	b1[0]=1,b2[0]=1;
	for(int i=1;i<=max(a[n].len,b[q].len)+1;i++) b1[i]=b1[i-1]*base,b2[i]=b2[i-1]*base2%mod;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i].len;j++)
		{
			a1[i].first*=base,a1[i].first+=a[i].s[j];
//			a1[i].second*=base2,a1[i].second+=a[i].s[j],a1[i].second%=mod;
			a2[i].first*=base,a2[i].first+=a[i].t[j];
//			a2[i].second*=base2,a2[i].second+=a[i].t[j],a2[i].second%=mod;
		}
	}
	for(int i=1;i<ax;i++) tong[{a1[i],a2[i]}]++;
	for(int i=bx;i<=n;i++)
	{
		for(int j=1;j<=b[i].len;j++)
			hs[j].first=hs[j-1].first*base+b[i].s[j],hs[j].second=(hs[j-1].second*base2+b[i].s[j])%mod;
		for(int j=1;j<=b[i].len;j++)
			ht[j].first=ht[j-1].first*base+b[i].t[j],ht[j].second=(ht[j-1].second*base2+b[i].t[j])%mod;
		int l=b[i].len,r=0;
		for(int j=1;j<=b[i].len;j++)
			if(b[i].s[j]!=b[i].t[j]) l=min(l,j),r=max(r,j);
		for(int j=ax;j<=n;j++)
		{
			pair<ull,int> x=a1[j],y=a2[j];
			for(int k=max(r-a[j].len+1,1ll);k<=min(l,b[i].len);k++)
				if(calc(k,k+a[j].len-1)==x&&calc2(k,k+a[j].len-1)==y) ans[b[i].id]++;
		}
		for(int len=r-l+1;len<=B;len++)
		{
			for(int ii=r-len+1;ii<=l;ii++)
			{
				int jj=ii+len-1;
				if(jj>b[i].len) break;
				ans[b[i].id]+=tong[{calc(ii,jj),calc2(ii,jj)}];
			}
		}
	}
	for(int i=1;i<bx;i++)
	{
		for(int j=1;j<=b[i].len;j++)
			hs[j].first=hs[j-1].first*base+b[i].s[j];
//			hs[j].second=(hs[j-1].second*base2+b[i].s[j])%mod;
		for(int j=1;j<=b[i].len;j++)
			ht[j].first=ht[j-1].first*base+b[i].t[j];
//			ht[j].second=(ht[j-1].second*base2+b[i].t[j])%mod;
		int l=b[i].len,r=0;
		for(int j=1;j<=b[i].len;j++)
			if(b[i].s[j]!=b[i].t[j]) l=min(l,j),r=max(r,j);
//		for(int ii=1;ii<=b[i].len;ii++)
//		{
//			for(int jj=ii;jj<=b[i].len;jj++)
//			{
//				if(!(ii<=l&&r<=jj)) continue;
//				ans[b[i].id]+=tong[{calc(ii,jj),calc2(ii,jj)}];
//			}
//		}	
		for(int len=r-l+1;len<=b[i].len;len++)
		{
			for(int ii=max(1ll,r-len+1);ii<=l;ii++)
			{
				int jj=ii+len-1;
				if(jj>b[i].len) break;
//				cout<<ii<<" "<<jj<<" "<<calc(ii,jj).first<<" "<<calc(ii,jj).second<<" "<<calc2(ii,jj).first<<" "<<calc2(ii,jj).second<<'\n';
				ans[b[i].id]+=tong[{calc(ii,jj),calc2(ii,jj)}];
			}
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}

//I'm the bone of the code
//Steel is my body,and fire is my blood
//I have writed over a thousand codes
//Unavare to loss,nor avare to gain
//Withstood pain to write many codes ,waiting for one's arrival.
//I have no regrets.This is the only path
//My whole life was "Unlimited Code Works".
//CSP-S2025 RP++
//死了 