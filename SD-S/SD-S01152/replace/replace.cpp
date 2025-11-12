//AC自动机保佑我AC
#include<bits/stdc++.h>
using namespace std;
namespace file_read{
	char ib[1<<25],*ip1=ib,*ip2=ib;
	inline char gc(){
		return (((ip1==ip2&&(ip2=(ip1=ib)+fread(ib,1,1<<24,stdin))),ip1==ip2?EOF:*ip1++));
	}
	inline int read(){//no long long!!!
		int x=0;char c=gc();
		while(c<'0'||c>'9')c=gc();
		while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^'0'),c=gc();
		return x;
	}
	inline int du(char* s){
		int h=0;
		char c=gc();
		while(c<'a'||c>'z')c=gc();
		while(c>='a'&&c<='z')s[++h]=c,c=gc();
		return h;
	}
}
using namespace file_read;
char ss1[5000005],ss2[5000005],tt1[5000005],tt2[5000005];//zhengge cunde zifushuzu
char* sd1[200005],*sd2[200005],*td1[200005],*td2[200005];//duiwei zhizhen
int ans[200005],S1[200005],S2[200005],T1[200005],T2[200005];//daan, changdu
int sl[200005],sr[200005],tl[200005],tr[200005];//zuoyou 568????????????568???????????????????568??????????????????????????
const long long mod=1ll*1000000009*1004535809,bb=131313131;
long long b1[200005],b2[200005];
int p1[200005],p2[200005];
bool f1[200005],f2[200005];
struct apple{
	#define N 2500000
	int ss[N+5][27],fl[N+5],cc[N+5],tot=1;
	void clear(){
		for(int i=0;i<=tot;++i){
			memset(ss[i],0,sizeof(ss[i]));
			fl[i]=cc[i]=0;
		}
		tot=1;
	}
	void getfail(){
		queue<int>q;
		q.emplace(1);fl[1]=0;
		for(int i=0;i<=26;++i)ss[0][i]=1;
		while(q.size()){
			int x=q.front();q.pop();
			for(int i=0;i<=26;++i){
				int y=ss[x][i];
				if(!y)ss[x][i]=ss[fl[x]][i];
				else fl[y]=ss[fl[x]][i],cc[y]+=cc[fl[y]],q.emplace(y);
			}
		}
	}
	inline int gsn(int r,char c){
		int d=c-'a';
		return ss[r][d]?ss[r][d]:(ss[r][d]=++tot);
	}
}AC;
const char jh='a'+26;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();//1<=n,q<=2e5
	sd1[1]=ss1,sd2[1]=ss2,td1[1]=tt1,td2[1]=tt2;
	for(int i=1;i<=n;++i){
		S1[i]=du(sd1[i]);sd1[i+1]=sd1[i]+S1[i];
		S2[i]=du(sd2[i]);sd2[i+1]=sd2[i]+S2[i];
		char* s1=sd1[i],*s2=sd2[i];
		int d=S1[i];
		sl[i]=1,sr[i]=d;
		while(sl[i]<=d&&s1[sl[i]]==s2[sl[i]])++sl[i];
		while(sr[i]>=1&&s1[sr[i]]==s2[sr[i]])--sr[i];
		if(sl[i]>sr[i]){
			p1[i]=i;f1[i]=1;continue;
		}
		int L=sl[i],R=sr[i];
		long long z=0;
		for(int j=L;j<=R;++j)z=((__int128)z*bb+s1[j])%mod;
		for(int j=L;j<=R;++j)z=((__int128)z*bb+s2[j])%mod;
		b1[i]=z,p1[i]=i;
	}
	for(int i=1;i<=q;++i){
		T1[i]=du(td1[i]);td1[i+1]=td1[i]+T1[i];
		T2[i]=du(td2[i]);td2[i+1]=td2[i]+T2[i];
		char* t1=td1[i],*t2=td2[i];
		int d=T1[i],dd=T2[i];
		if(d!=dd){
			p2[i]=i;f2[i]=1;continue;
		}
		tl[i]=1,tr[i]=d;
		while(tl[i]<=d&&t1[tl[i]]==t2[tl[i]])++tl[i];
		while(tr[i]>=1&&t1[tr[i]]==t2[tr[i]])--tr[i];
		if(tl[i]>tr[i]){
			p2[i]=i;f2[i]=1;continue;
		}
		int L=tl[i],R=tr[i];
		long long z=0;
		for(int j=L;j<=R;++j)z=((__int128)z*bb+t1[j])%mod;
		for(int j=L;j<=R;++j)z=((__int128)z*bb+t2[j])%mod;
		b2[i]=z,p2[i]=i;
	}
	sort(p1+1,p1+n+1,[&](int x,int y){
		return b1[x]<b1[y];
	});
	sort(p2+1,p2+q+1,[&](int x,int y){
		return b2[x]<b2[y];
	});
	int w1=1;
	for(int ii=1;ii<=q;){
		int jj=ii;AC.clear();
		long long b=b2[p2[ii]];
		while(w1<=n&&b1[p1[w1]]<=b){
			if(f1[p1[w1]]){
				++w1;continue;
			}
			if(b1[p1[w1]]<b){
				++w1;continue;
			}
			int x=p1[w1++],r=1,cd=S1[x];char* s1=sd1[x];
			for(int i=1;i<sl[x];++i)r=AC.gsn(r,s1[i]);
			r=AC.gsn(r,jh);
			for(int i=sr[x]+1;i<=cd;++i)r=AC.gsn(r,s1[i]);
			++AC.cc[r];
		}
		AC.getfail();
		while(jj<=q&&b2[p2[jj]]==b){
			if(f2[p2[jj]]){
				++jj;continue;
			}
			int x=p2[jj++],r=1,cd=T1[x];char* t1=td1[x];
			for(int i=1;i<tl[x];++i)r=AC.gsn(r,t1[i]);
			ans[x]+=AC.cc[r=AC.gsn(r,jh)];
			for(int i=tr[x]+1;i<=cd;++i)ans[x]+=AC.cc[r=AC.gsn(r,t1[i])];
		}
		ii=jj;
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}
