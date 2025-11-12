#include<bits/stdc++.h>
using namespace std;
const long long mod1=998244353;
const long long mod2=1000000007;
const long long inf=0x3f3f3f3f3f3f3f3f;
const long long base=119283779;
const long long invbase=348925297;
const long long mod=1192837643;
const long long MAXN=200011;
long long n,m;
long long sts[MAXN],ens[MAXN],dif[MAXN];
long long ssiz[MAXN];
long long hashs[MAXN][2];
long long hashst[MAXN],hashen[MAXN];
unordered_map<long long,vector<long long> >f;

void init();
void domemset();
long long read();
void write(long long x);

long long hashit(string x,long long st,long long en)
{
	long long sum=0;
	for(int i=st;i<=en;i++)
		sum=(sum*base+x[i]-'a')%mod;
	return sum;
}
long long ksm(long long a,long long b)
{
	long long sum=1;
	while(b)
	{
		if(b&1)
			sum=sum*a%mod;
		a=a*a%mod;
		b>>=1; 
	}
	return sum;
}

vector<long long>tmphashst,tmphashen;

void fun()
{
	domemset();
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		string x,y;
		cin>>x>>y;
		ssiz[i]=x.size();
		for(int j=0;j<x.size();j++)
			if(x[j]!=y[j])
			{
				sts[i]=j;break;
			}
		for(int j=x.size()-1;j>=0;j--)
			if(x[j]!=y[j])
			{
				ens[i]=j;break;
			}
		dif[i]=ens[i]-sts[i]+1;
		hashs[i][0]=hashit(x,0,x.size()-1);hashs[i][1]=hashit(y,0,y.size()-1);
		long long difhash=((hashs[i][0]-hashs[i][1])*ksm(invbase,x.size()-ens[i]-1)%mod+mod)%mod;
		difhash=(difhash*base+x[sts[i]]-'a')%mod;
		difhash=(difhash*base+x[ens[i]]-'a')%mod;
//		if(difhash==369782428)
//			cout<<x<<" "<<y<<endl<<difhash<<" "<<hashst[i]<<" "<<hashen[i]<<endl;
		f[difhash].push_back(i);
		hashst[i]=hashit(x,0,sts[i]-1);hashen[i]=hashit(x,ens[i]+1,x.size()-1);
//		cout<<difhash<<" "<<hashst[i]<<" "<<hashen[i]<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		string x,y;
		long long ans=0;
		cin>>x>>y;
		if(x.size()!=y.size())
		{
			putchar('0'),putchar('\n');
			continue;
		}
		long long st=-1,en=-1;
		for(int j=0;j<x.size();j++)
			if(x[j]!=y[j])
			{
				st=j;break;
			}
		for(int j=x.size()-1;j>=0;j--)
			if(x[j]!=y[j])
			{
				en=j;break;
			}
		long long hashx=hashit(x,0,x.size()-1),hashy=hashit(y,0,y.size()-1);
		long long difhash=((hashx-hashy)*ksm(invbase,x.size()-en-1)%mod+mod)%mod;
		difhash=(difhash*base+x[st]-'a')%mod;
		difhash=(difhash*base+x[en]-'a')%mod;
		vector<long long>tmp=f[difhash];
		tmphashst.clear();tmphashen.clear();
		tmphashst.push_back(0);tmphashen.push_back(0);
		long long lst=0;
		for(int j=0;j<st;j++)
			tmphashst.push_back(((lst*base+x[j]-'a')%mod+mod)%mod),lst=((lst*base+x[j]-'a')%mod+mod)%mod;
		lst=0;
		for(int j=en+1;j<x.size();j++)
			tmphashen.push_back(((lst*base+x[j]-'a')%mod+mod)%mod),lst=((lst*base+x[j]-'a')%mod+mod)%mod;
//		cout<<difhash<<" "<<tmp.size()<<endl;
		for(int i=0;i<tmp.size();i++)
		{
			long long num=tmp[i];
			if(ens[num]-sts[num]!=en-st)
				continue;
			if(ssiz[num]-ens[num]>x.size()-en||sts[num]>st)
				continue;
//			cout<<((tmphashst[st]-tmphashst[st-sts[num]]*ksm(base,sts[num])%mod)%mod+mod)%mod<<" "<<tmphashen[ssiz[num]-ens[num]-1]<<endl;
			
			if(((tmphashst[st]-tmphashst[st-sts[num]]*ksm(base,sts[num])%mod)%mod+mod)%mod==hashst[num]&&tmphashen[ssiz[num]-ens[num]-1]==hashen[num])
				ans++;
		}
		write(ans),putchar('\n');
	}
	return ;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(NULL));
	init();
//	t=read();
//	for(int i=1;i<=t;i++)
//	while(1)
		fun();
	return 0;
}


void init()
{

	return ;
}
void domemset()
{

	return ;
}
long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^'0');
		ch=getchar();
	}
	return x*f;
}
void write(long long x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>=10)
		write(x/10);
	putchar((x%10)^'0');
	return ;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

/*
xn ks
*/
