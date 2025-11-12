#include<bits/stdc++.h>
//#define DBG

#ifdef DBG
#define dbg(...) fprintf(stderr,__VA_ARGS__)
#else
#define dbg(...) void()
#endif

#define il inline __attribute((always_inline))

using u32=unsigned int;
using i64=long long;
using u64=unsigned long long;

template<typename T=int>
T read(){
	T x=0;char c=getchar(),f=0;
	while(c<'0'||'9'<c) f=(c=='-'),c=getchar();
	while('0'<=c&&c<='9') x=x*10+(c&15),c=getchar();
	return f?-x:x;
}

template<typename T>
void print(T x){
	if(x==0) return putchar('0'),void();
	if(x<0) putchar('-'),x=-x;
	if(x>=10) print(x/10),x%=10;
	putchar(x|'0');
}

const u32 mod1=998244343,mod2=1000'000'007;
const u32 bas1=113;
u32 bas2,hash1[10000'010],hash2[10000'010],pw1[10000'010],pw2[10000'010];

char S[10000'010];

u64 geth(int l,int r){
	u32 h1=(hash1[r]+u64(mod1-hash1[l-1])*pw1[r-l+1])%mod1;
//	h1=0;
	u32 h2=(hash2[r]+u64(mod2-hash2[l-1])*pw2[r-l+1])%mod2;
	return (((u64)h1)<<32)|h2;
}

struct STR{
	int l,r;
	int size()const{return r-l;}
	char& operator [] (const int &p)const{
		return S[l+p];
	}
	
	STR substr(std::array<int,2> rg)const{
		return {l+rg[0],l+rg[1]+1};
	}
	STR substr(int s,int t)const{
		return {l+s,l+t};
	}
	STR pre(int x){
		return {l,l+x};
	}
	STR suf(int x){
		return {l+x,r};
	}
	
	void print()const{
		int i;
		for(i=l;i<r;++i) dbg("%c",S[i]+'a'-1);
	}
	u64 gethash()const{
		return geth(l,r-1);
	}
	bool ispre(const STR &o) const{
		return size()>=o.size()&&substr(0,o.size())==o;
	}
	bool operator == (const STR &o){
		if(size()!=o.size()) return false;
		return gethash()==o.gethash();
	}
};

bool operator < (STR a,STR b){
	int len=std::min(a.size(),b.size());
	int l=0,r=len,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(a.pre(mid)==b.pre(l)) l=mid+1;
		else r=mid;
	}
	if(l==len) return a.size()<b.size();
	return a[l]<b[l];
}

char snow[5000'010];
int cnts;

STR readstr(){
	scanf("%s",snow);
	int n=strlen(snow),l=cnts+1,i;
	for(i=0;i<n;++i) S[++cnts]=snow[i]-'a'+1;
	return {l,cnts+1};
}

STR s[200010][2],t[200010][2];
std::array<int,2> srg[200010],trg[200010];

std::array<int,2> RG(STR a,STR b){
	int n=a.size();
	int l=0,r=n-1;
	while(l<n&&a[l]==b[l]) ++l;
	while(r&&a[r]==b[r]) --r;
	return {l,r};
}

std::map<u64,std::vector<STR>> vec;

u64 mergehash(std::vector<STR> cur){
	u64 now;
	u32 h1=0,h2=0,nowh1,nowh2;
	for(auto s:cur){
		now=s.gethash();
		nowh1=now>>32;
		nowh2=now&u32(-1);
		h1=((u64)h1*pw1[s.size()]+nowh1)%mod1;
		h2=((u64)h2*pw2[s.size()]+nowh2)%mod2;
	}
	return (((u64)h1)<<32)|h2;
}

int trie[10000'010][26],cntnod=1;

int ins(STR str){
	int p=1,i;
	for(i=0;i<str.size();++i){
		if(!trie[p][str[i]]) trie[p][str[i]]=++cntnod;
		p=trie[p][str[i]];
	}
	return p;
}

int find(STR str){
	int p=1,i;
	for(i=0;i<str.size();++i){
		if(!trie[p][str[i]]) break;
		p=trie[p][str[i]];
	}
	return p;
}

//std::map<u64,std::array<int,2>>

int main(){
#ifndef ZIGAO
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
#endif
	
	std::mt19937 mt(time(0));
	bas2=mt()%mod2;
//	bas2=10;
	
	int i,j,res,n=0,cnt=0;
	int N=read();
	int q=read();
	for(i=0;i<N;++i){
		s[i][0]=readstr();
		s[i][1]=readstr();
	}
	for(i=0;i<q;++i){
		t[i][0]=readstr();
		t[i][1]=readstr();
	}
	dbg("%lf\n",1.0*clock()/CLOCKS_PER_SEC);
	
	for(i=pw1[0]=pw2[0]=1;i<=cnts;++i){
		pw1[i]=(u64)pw1[i-1]*bas1%mod1;
		pw2[i]=(u64)pw2[i-1]*bas2%mod2;
		hash1[i]=((u64)hash1[i-1]*bas1+S[i])%mod1;
		hash2[i]=((u64)hash2[i-1]*bas2+S[i])%mod2;
	}
	
	
	for(i=0;i<N;++i){
		srg[i]=RG(s[i][0],s[i][1]);
		if(srg[i][0]<=srg[i][1]){
			srg[n]=srg[i];
			s[n][0]=s[i][0];
			s[n][1]=s[i][1];
			n++;
		}
	}
	
	for(i=0;i<n;++i){
		auto [sl,sr]=srg[i];
		vec[mergehash({
			s[i][0].pre(sl),
			s[i][0].substr(sl,sr+1),
			s[i][1].substr(sl,sr+1)
		})].push_back(s[i][0].suf(sr+1));
//		int p=ins(s[i][0].suf(sr+1));
//		dbg("add:%llu ",mergehash({
//			s[i][0].pre(sl),
//			s[i][0].substr(sl,sr+1),
//			s[i][1].substr(sl,sr+1)
//		}));
//		s[i][0].suf(sr+1).print();
//		dbg("\n");
	}
	
//	for(auto &[h,v]:vec) std::sort(v.begin(),v.end());
	
	dbg("%d\n%lf\n",n,1.0*clock()/CLOCKS_PER_SEC);

	
//	for(i=0;i<n;++i){
//		s[i][0].print();
//		dbg(" ");
//		s[i][1].print();
//		dbg("\n");
//		dbg("rg:%d %d\nhash:%llu %llu\n\n",srg[i][0],srg[i][1],s[i][0].gethash(),s[i][1].gethash());
//	}

	for(i=0;i<q;++i){
		res=0;
		if(t[i][0].size()==t[i][1].size()){
			++cnt;
			trg[i]=RG(t[i][0],t[i][1]);
			auto [tl,tr]=trg[i];
			STR ss=t[i][0].suf(tr+1);
//			dbg("ss:");
//			ss.print();
//			dbg("\n");
			
			for(j=0;j<=tl;++j){
				auto &v=vec[mergehash({
					STR(t[i][0].substr(j,tl)),
					STR(t[i][0].substr(tl,tr+1)),
					STR(t[i][1].substr(tl,tr+1)),
				})];
				for(auto s:v) if(ss.ispre(s)) ++res;
			}
		}
		print(res),putchar('\n');
	}
	dbg("%d\n%lf\n",cnt,1.0*clock()/CLOCKS_PER_SEC);
	
	return 0;
}