#include<bits/stdc++.h>
#define base 131
#define mod 998244353
#define ll long long
using namespace std;
inline int read(){
	char ch=getchar();
	int x=0;
	while(ch>'9'||ch<'0')ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}inline void write(int x){
	if(!x)return putchar('0'),void();
	char ch[40];int cnt=0;
	while(x)ch[++cnt]=x%10^48,x/=10;
	while(cnt)putchar(ch[cnt--]);
}
ll p[5000005];
ll pp[5000005];
char ch1[5000005],ch2[5000005];
ll hsh[2][5000005];
ll hshh[2][5000005];
ll gethsh(ll hsh[],int l,int r){
	if(l>r)return 0;
	return hsh[r]-hsh[l-1]*p[r-l+1];
}ll gethshh(ll hsh[],int l,int r){
	if(l>r)return 0;
	return ((hsh[r]-hsh[l-1]*pp[r-l+1]%mod)%mod+mod)%mod;
}
ll core[100005][2];
ll corr[100005][2];
int cl[100005],cr[100005];
ll pre[100005],suf[100005];
ll pree[100005],suff[100005];
vector<int>id[100005];
map<pair<ll,ll>,int>mp[100005];
string s1[100005],s2[100005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;scanf("%d%d",&n,&q);
	p[0]=1;
	pp[0]=1;
	for(int i=1; i<=5000000; i++)p[i]=p[i-1]*base,pp[i]=pp[i-1]*base%mod;
	int cnt=0;
	for(int i=1; i<=n; i++){
		scanf("%s",ch1+1);
		scanf("%s",ch2+1);
		int len=strlen(ch1+1);
		s1[i]=ch1+1,s2[i]=ch2+1;
		int l=len,r=1;
		for(int j=1; j<=len; j++){
			hsh[0][j]=hsh[0][j-1]*base+(ch1[j]);
			hsh[1][j]=hsh[1][j-1]*base+(ch2[j]);
			hshh[0][j]=(hshh[0][j-1]*base%mod+(ch1[j]))%mod;
			hshh[1][j]=(hshh[1][j-1]*base%mod+(ch2[j]))%mod;
		}
		for(int j=1; j<=len; j++){
			if(ch1[j]!=ch2[j]){
				l=j;
				break;
			}
		}for(int j=len; j>=1; j--){
			if(ch1[j]!=ch2[j]){
				r=j;
				break;
			}
		}
		if(l<=r){
			core[i][0]=gethsh(hsh[0],l,r);
			core[i][1]=gethsh(hsh[1],l,r);
			corr[i][0]=gethshh(hshh[0],l,r);
			corr[i][1]=gethshh(hshh[1],l,r);
			
			cl[i]=l-1,cr[i]=len-r;
			pre[i]=gethsh(hsh[0],1,l-1);
			suf[i]=gethsh(hsh[1],r+1,len);
			pree[i]=gethshh(hshh[0],1,l-1);
			suff[i]=gethshh(hshh[1],r+1,len);
			if(mp[r-l+1][make_pair(corr[i][0],corr[i][1])]==0)cnt++,mp[r-l+1][make_pair(corr[i][0],corr[i][1])]=cnt;
			int ttt=mp[r-l+1][make_pair(corr[i][0],corr[i][1])];
			id[ttt].push_back(i);
		}
	}
	for(int i=1; i<=q; i++){
		scanf("%s",ch1+1);
		scanf("%s",ch2+1);
		int len=strlen(ch1+1);
		string S1=ch1+1,S2=ch2+1; 
		int l=len,r=1;
		for(int j=1; j<=len; j++){
			hsh[0][j]=hsh[0][j-1]*base+(ch1[j]);
			hsh[1][j]=hsh[1][j-1]*base+(ch2[j]);
			hshh[0][j]=(hshh[0][j-1]*base%mod+(ch1[j]))%mod;
			hshh[1][j]=(hshh[1][j-1]*base%mod+(ch2[j]))%mod;
		}
		for(int j=1; j<=len; j++){
			if(ch1[j]!=ch2[j]){
				l=j;
				break;
			}
		}for(int j=len; j>=1; j--){
			if(ch1[j]!=ch2[j]){
				r=j;
				break;
			}
		}ll core0,core1;
		core0=gethsh(hsh[0],l,r),core1=gethsh(hsh[1],l,r);
		ll corr0,corr1;
		corr0=gethshh(hshh[0],l,r),corr1=gethshh(hshh[1],l,r);
		if(mp[r-l+1][make_pair(corr0,corr1)]==0)printf("0\n");
		else{
			int tmp=mp[r-l+1][make_pair(corr0,corr1)],cnt=0;
			for(int j=0; j<id[tmp].size(); j++){
				int x=id[tmp][j];
				ll pr,sf;pr=sf=0;
				ll prr,sff;prr=sff=0;
				if(l!=1){
					int L=l-cl[x],R=l-1;
					pr=gethsh(hsh[0],L,R);
					prr=gethshh(hshh[0],L,R);
					if(L<1)pr=prr=0;
				}if(r!=len){
					int L=r+1,R=r+cr[x];
					sf=gethsh(hsh[0],L,R);
					sff=gethshh(hshh[0],L,R);
					if(R>len)sf=sff=0;
				}
				cnt+=(pr==pre[x]&&sf==suf[x]&&prr==pree[x]&&sff==suff[x]&&core0==core[x][0]&&core1==core[x][1]);
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}/*
fc replace.out replace3.ans
*/

