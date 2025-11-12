/*
记住，freopen前不可以读入！


*/
#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define ls (id<<1)
#define rs (id<<1|1)
inline int read(){
	int sum=0,k=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){sum=sum*10+c-48;c=getchar();}
	return sum*k;
}
using namespace std;
const int M=2e5+110;
//struct Node{
//	int lz,rz;mutable int val;
//	Node(int lz,int rz=0,int val=0):lz(lz),rz(rz),val(val){};
//	inline bool operator<(const Node &x)const{
//		return x.lz<lz;
//	}
//};set<Node>s;
//inline auto split(int pos){
//	auto it=s.lower_bound(Node(pos));
//	if(it!=s.end()&&it->lz==pos) return it;
//	it--;
//	if(it->rz<=pos) return s.end();
//	int l=it->lz,r=it->rz,val=it->val;
//	s.erase(it);
//	s.insert(Node(l,pos-1,val));
//	return s.insert(Node(pos,r,val)).fi;
//}
int T,n,ans;
struct Node{
	int a,b,c,mx,mi,va;
	inline void init(){
		mx=(a>b)?((a>c)?(a):(c)):((b>c)?(b):(c));
		mi=((mx==a)?max(b,c):(mx==b)?max(a,c):max(a,b));
		va=mx-mi;
	}
	inline bool operator<(const Node &x)const{
		return x.va<va;	
	}
}x;
priority_queue<Node,vector<Node>,less<Node>>a,b,c;
int sa,sb,sc,ok;
inline void work(){
	n=read();ans=0;
	sa=sb=sc=ok=0;
	for(int i=1;i<=n;i++){
		x.a=read(),x.b=read(),x.c=read();
		x.init();
		if(x.a==x.mx){
			if(sa==(n/2)){
				ok=1;
				Node u=a.top();
				if(x.va>=u.va){
					a.pop();
					a.push(x);
					ans+=u.mi;
				}else ans+=x.mi;
			}else if(ok==0) a.push(x),sa++;
			else ans+=x.mx;
		}
		else if(x.b==x.mx){
			if(sb==(n/2)){
				ok=1;
				Node u=b.top();
				if(x.va>=u.va){
					b.pop();
					b.push(x);
					ans+=u.mi;
				}else ans+=x.mi;
			}else if(ok==0) b.push(x),sb++;
			else ans+=x.mx;
		}
		else if(x.c==x.mx){
			if(sc==(n/2)){
				ok=1;
				Node u=c.top();
				if(x.va>=u.va){
					c.pop();
					c.push(x);
					ans+=u.mi;
				}else ans+=x.mi;
			}else if(ok==0) c.push(x),sc++;
			else ans+=x.mx;
		}
	}
	while(!a.empty()) ans+=a.top().mx,a.pop();
	while(!b.empty()) ans+=b.top().mx,b.pop();
	while(!c.empty()) ans+=c.top().mx,c.pop();
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) work();
	return 0;
}
/*
你可以发现，要么选最大的，要么选次大的，反悔贪心？
*/