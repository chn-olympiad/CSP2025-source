#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>

const int N=3e5+10;
int n,m,k;
template <typename T> void tomax(T &a,const T &b){if(a<b) a=b;}
template <typename T> void tomin(T &a,const T &b){if(b<a) a=b;}
void modadd(int &a,const int &b,const int &Mod){
	a+=b;
	if(a<0) a+=Mod;
	else if(a>=Mod) a-=Mod;
}
void modsub(int &a,const int &b,const int &Mod){
	a-=b;
	if(a<0) a+=Mod;
	else if(a>=Mod) a-=Mod;
}
void modmul(int &a,const int &b,const int &Mod){
	a=1ll*a*b%Mod;
}

const int B=13331,Mod=1e8+7;
struct Hash{
	int Base[N];
	int hs[N];
	void init(char s[])
	{
		Base[0]=1;
		for(int i=1;s[i];i++)
		{
			Base[i]=1ll*Base[i-1]*B%Mod;
			hs[i]=(1ll*hs[i-1]*B%Mod+s[i]-'a')%Mod;
		}
	}
	int gethash(int l,int r)
	{
		if(l>r)  return 0;
		return (hs[r]-(1ll*Base[r-l+1]*hs[l-1]%Mod)+Mod)%Mod;
	}
}ss,tt;


void dohash(char s[],const int &Mod,int &ans)
{
	ans=0;
	for(int i=1;s[i];i++)
	{
		ans=(1ll*ans*B%Mod+s[i]-'a')%Mod;
	}
}

int whe[N];
int len[N];
int sh[N];
int th[N];
char s[N],t[N];

void SOLVE()//40pts
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s %s",s+1,t+1);
		dohash(s,Mod,sh[i]);
		dohash(t,Mod,th[i]);
		int k=strlen(s+1);len[i]=k;
		if(sh[i]==th[i]) whe[i]=k;
		else for(int j=1;j<=k;j++)
		{
			if(s[j]!=t[j])
			{
				whe[i]=j;
				break;
			}
		}
	}
	for(int qq=1;qq<=m;qq++)
	{
		scanf("%s %s",s+1,t+1);
		ss.init(s),tt.init(t);
		int k=strlen(s+1);
		int ww=0;
		int res=0;
		for(int j=1;j<=k;j++)
		{
			if(s[j]!=t[j])
			{
				ww=j;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(ww<whe[i])  continue;
			else
			{
				int l=ww-whe[i]+1;
				int r=l+len[i]-1;
//				printf("i=%d:l=%d r=%d  %d==%d  %d==%d\n",i,l,r,ss.gethash(l,r),sh[i],tt.gethash(l,r),th[i]);
				if(r>k) continue;
				if(ss.gethash(l,r)==sh[i]&&tt.gethash(l,r)==th[i]&&ss.gethash(r+1,k)==tt.gethash(r+1,k))
				{
					res++;
//					printf("%d isok:\n",i);
				}
			}
		}
		printf("%d\n",res);
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	while(T--) SOLVE();
	return 0;
}
