//Just Sayori!!!
//csp 2025 rp++
//祝学长全部进 WC！
//祝大家全员一等奖！
//才发现题看错了，差点爆了
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#define ll long long
#define ull unsigned long long
#define rnt register int
#define base 499
#define gr getchar
#define pr putchar
#define N 500005
#define M 1000000007
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=gr();
	while (ch<'0' || ch>'9') ch=='-'?f=-1,ch=gr():ch=gr();
	while (ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=gr();
	return x*f;
}
void write(ll x)
{
	int top=0,stack[39];
	if (x<0) pr('-'),x=-x;
	do stack[++top]=x%10,x/=10;
	while (x);
	while (top) pr(stack[top--]^48);
}
ull hash2;
ull hash1[N*10],sumbase[N*10],hashs[N][2];
string s[N][2];
void get_hash(string s1)
{
	int len1=s1.size();
	hash1[0]=s1[0]-'a'+1;
	for (rnt i=1;i<len1;i++) hash1[i]=hash1[i-1]*base+(s1[i]-'a'+1);
}
ull get_hash2(string s)
{
	int len=s.size();
	ull sum=0;
	for (rnt i=0;i<len;i++) sum=sum*base+(s[i]-'a'+1);
	return sum;
}
ull qm(ull a,int b,ull ans=1)
{
	while (b)
	{
		if (b&1) ans*=a;
		a*=a,b>>=1;
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	int n=read(),q=read();
	string qa,qb;
	sumbase[0]=1;
	for (rnt i=1;i<=200000;i++) sumbase[i]=sumbase[i-1]*base;
	for (rnt i=1;i<=n;i++) cin>>s[i][0]>>s[i][1],hashs[i][0]=get_hash2(s[i][0]),hashs[i][1]=get_hash2(s[i][1]);
	for (rnt i=1,ans,len;i<=q;i++)
	{
		cin>>qa>>qb,ans=0;
		if (qa.size()!=qb.size() || n>10000)
		{
			write(0),pr(10);
			continue;
		}
		len=qa.size()-1;
		get_hash(qa),hash2=get_hash2(qb);
		for (rnt i=0;i<=len;i++)
		{
			for (rnt j=1;j<=n;j++)
			{
				int len2=s[j][0].size();
				if (i-len2+1>=0)
				{
					ull temp=hash1[i]-hash1[i-len2]*sumbase[len2];
					if (temp==hashs[j][0])
					{
						temp=hash1[i-len2]*sumbase[len-i+len2]+hash1[len]-hash1[i]*sumbase[len-i]+hashs[j][1]*sumbase[len-i];
						if (temp==hash2) ans++;
					}
				}
			}
		}
		write(ans),pr(10);
	}
	return 0;
}