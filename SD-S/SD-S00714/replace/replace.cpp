#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int rd(){int res=0,f=1;char x=getchar();
	while(x<'0'||'9'<x){if(x=='-')f*=-1;x=getchar();}
	while('0'<=x&&x<='9')res=res*10+x-'0',x=getchar();
return res*f;}
void wt(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)wt(x/10);
	putchar(x%10+'0');
return;}
const int N=2e5+100,L=5e6+100;
const int BASE=29,MOD=1e9+7;
string t1,t2;
int n,q;
int base[L];
struct strs{
	int trf,trs,trn,prh,lsh;//truefir,truesec,truename,prehash,lasthash;
	int l=0,r=0,len;
	inline void init(){trf=trs=trn=prh=lsh=0;}
}book[N],tmp;
int tmp1[L][2];
int gth(int l,int r,int id){
//	cerr<<(tmp1[r][id]-tmp1[l-1][id]*base[r-l]%MOD+MOD)%MOD<<endl;
	return (tmp1[r][id]-tmp1[l-1][id]*base[r-l]%MOD+MOD)%MOD;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=rd(),q=rd();base[0]=BASE;
	for(int i=1;i<L;i++)base[i]=base[i-1]*BASE%MOD;
	for(int i=1;i<=n;i++){
		cin>>t1>>t2;int len=t1.size();book[i].len=len;
		int l=0,r=len-1,bast=1;
		for(int j=0;j<len;j++)
			if(t1[j]!=t2[j]){l=j;break;}
			else book[i].prh=(book[i].prh*BASE+t1[j])%MOD;
		for(int j=len-1;j>=0;j--)
			if(t1[j]!=t2[j]){r=j;break;}
		book[i].l=l-1,book[i].r=r+1;
		for(int j=r+1;j<len;j++)
			book[i].lsh=(book[i].lsh*BASE+t1[j])%MOD;
		for(int j=l;j<=r;j++)	bast=bast*BASE%MOD,
			book[i].trf=(book[i].trf*BASE+t1[j])%MOD,
			book[i].trs=(book[i].trs*BASE+t2[j])%MOD;
		book[i].trn=(book[i].trf*bast%MOD+book[i].trs)%MOD;
	}
	while(q--){
		cin>>t1>>t2;
		int len=t1.size(),l=0,r=len-1,bast=1;
		if(len!=t2.size()){wt(0),putchar(endl);continue;}
		tmp.init();
		tmp1[0][0]=tmp1[0][1]=0;
		for(int i=0;i<len;i++)
			if(t1[i]!=t2[i]){l=i;break;}
			else tmp1[i][0]=(tmp1[max(i-1,0LL)][0]*BASE+t1[i])%MOD;
		for(int i=len-1;i>=0;i--)
			if(t1[i]!=t2[i]){r=i;break;}
		for(int i=r+1;i<len;i++)
			tmp1[i][1]=(tmp1[max(i-1,0LL)][1]*BASE+t1[i]);
		for(int i=l;i<=r;i++)	bast=bast*BASE%MOD,
			tmp.trf=(tmp.trf*BASE+t1[i])%MOD,
			tmp.trs=(tmp.trs*BASE+t2[i])%MOD;
		tmp.trn=(tmp.trf*bast%MOD+tmp.trs)%MOD;
		int ans=0;//cerr<<r<<endl;
		for(int i=1;i<=n;i++){
			if(tmp.trn==book[i].trn){bool flag=1;
//				cerr<<i<<endl;
				if(book[i].l>=0){//l-(book[i].l+1)~l-1
					if(gth(l-(book[i].l+1),l-1,0)!=book[i].prh){
//						cerr<<i<<" had died at l("<<l-(book[i].l+1)<<','<<l-1<<")\n";
//						cerr<<"note:\nbook was:"<<book[i].prh<<"\nget was:"<<gth(l-(book[i].l+1),l-1,0)<<endl;
						flag=0;
					}
				}if(book[i].r<book[i].len){
					if(gth(r+1,r+(book[i].len-book[i].r),1)!=book[i].lsh){
//						cerr<<i<<"had died at r"<<r+1<<' '<<r+(book[i].len-book[i].r)<<endl;
//						cerr<<"note:\nbook was:"<<book[i].lsh<<"\nget was:"<<gth(r+1,r+(book[i].len-book[i].r+1),1)<<endl;
						flag=0;
					}
				}ans+=flag;
			}
		}wt(ans),putchar(endl);
	}
	return 0;
}
/*
6 2
xabcx xadex
abcx adex
abc ade
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
