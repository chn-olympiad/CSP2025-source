#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;

inline ll readl(){
	ll x=0,y=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')y=-y;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c&15);
		c=getchar();
	}
	return x*y;
}
inline string readstr(){
	string s="";char c=getchar();
	while(c<'a'||c>'z') c=getchar();
	while(c>='a'&&c<='z') s+=c,c=getchar();
	return s;
}

void writel(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else writel(x/10),putchar(x%10+'0');
}
ll n,q;
const ll N=2e5+10;

namespace StringHash_Frog{
	struct SHash{
		ll h1,h2;
	};
	const ll Mod1=998244353,Mod2=1000000007;
	const ll k=26;
	ll K1[10000010],K2[10000010];
	inline ll f(char c){return c-'a';}
	inline void Init(){
		K1[0]=K2[0]=1;
		for(ll i=1;i<=10000000;i++){
			K1[i]=K1[i-1]*k%Mod1;
			K2[i]=K2[i-1]*k%Mod2;
		}
	}
	inline ll Hash1(string x){
		ll sz=x.length();
		ll sum=0;
		for(ll i=0;i<sz;i++){
			sum+=f(x[i])*K1[i]%Mod1;
			sum%=Mod1;
		}
		return sum;
	}
	inline ll Hash2(string x){
		ll sz=x.length();
		ll sum=0;
		for(ll i=0;i<sz;i++){
			sum+=f(x[i])*K2[i]%Mod2;
			sum%=Mod2;
		}
		return sum;
	}	
	inline SHash SHash_f(string x){
		return (SHash){Hash1(x),Hash2(x)};
	}
	ll kkk(SHash x){
		return x.h1*19260817+x.h2;
	}
//	void HashS1(ll ind){
//		ll len
//	}
}
using namespace StringHash_Frog;



string s1,s2,t1,t2,Pre,Nxt,Dif;
struct Sepe{
	string pre,nxt,dif;
}S[N];
SHash dif_h[N],pre_h[N],nxt_h[N],Dif_h;

vector<vector<ll> >Bucket;
unordered_map<ll,ll> turner;ll timer;
inline void addd(ll i){
	ll sc03=kkk(dif_h[i]);
	if(!turner[sc03]) turner[sc03]=++timer,Bucket.push_back(vector<ll>());;
	Bucket[turner[sc03]].push_back(i);
//	cerr<<S[i].dif<<':'<<dif_h[i].h1<<','<<dif_h[i].h2<<": "<<sc03<<"\n";
}



inline void Seperate(ll ind){
	ll sz=s1.length();
	ll i=0,j=sz-1;
	while(s1[i]==s2[i]&&i<sz) S[ind].pre+=s1[i],i++;
	while(s1[j]==s2[j]&&j>=i) S[ind].nxt+=s2[j],j--;
	for(ll k=i;k<=j;k++) S[ind].dif+=s1[k],S[ind].dif+=s2[k];
	dif_h[ind]=SHash_f(S[ind].dif);
	pre_h[ind]=SHash_f(S[ind].pre);
	nxt_h[ind]=SHash_f(S[ind].nxt);
}
inline void Seperate2(){
	ll sz=t1.length();
	ll i=0,j=sz-1;
	while(t1[i]==t2[i]&&i<sz) Pre+=t1[i],i++;
	while(t1[j]==t2[j]&&j>=i) Nxt+=t2[j],j--;
	for(ll k=i;k<=j;k++) Dif+=t1[k],Dif+=t2[k];
	Dif_h=SHash_f(Dif);
}

//struct Trie{
//	struct Node{
//		int ind,val;
//		int to[26];
//		Node(ll a=0,ll b=0){
//			val=b,ind=a;
//			memset(to,0,sizeof to);
//		}
//	};
//	vector<Node>tr;ll tot;
//	Trie(){
//		tr.push_back(Node());tot=0;
//	}
//	void upd(string x){
//		ll now=0;
//		for(ll i=0;i<x.length();i++){
//			char cc=x[i];ll c=(cc-'a');
//			if(!tr[now].to[c])
//				tr.push_back(Node(c,0)),tot++,
//				tr[now].to[c]=tot;
//			now=tr[now].to[c];
//		}
//		tr[now].val++;
//	}
//	ll que(string x){
//		ll s=0;
//		ll now=0;
//		for(ll i=0;i<x.length();i++){
//			char cc=x[i];ll c=(cc-'a');
//			if(!tr[now].to[c])return s;
//			now=tr[now].to[c];
//			s+=tr[now].val;
//		}
//		return s;
//	}
//}pp,nn;


inline string rev(string x){
	string t="";
	for(ll i=x.length()-1;i>=0;i--) t+=x[i];
	return t;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=readl(),q=readl();
	Init();
	Bucket.push_back(vector<ll>());
	for(ll i=1;i<=n;i++){
		s1=readstr();
		s2=readstr();
		Seperate(i);
//		cerr<<S[i].pre<<'+'<<S[i].dif<<'+'<<S[i].nxt<<'\n';
		addd(i);
	}
	
//	for(ll i=1;i<=timer;i++){
//		for(ll j:Bucket[i]){
//			string a1=S[j].pre,a2=S[j].nxt;
//			a1=rev(a1);
//			pp.upd(a1);nn.upd(a2);
//		}
//	}
//	for(ll i=1;i<=q;i++){
//		Pre="",Nxt="",Dif="";
//		t1=readstr();
//		t2=readstr();
//		Seperate2();
//		
//	}
//	cerr<<"--------------------------------\n";
	for(ll i=1;i<=q;i++){
		Pre="",Nxt="",Dif="";
		t1=readstr();
		t2=readstr();
		Seperate2();
//		cerr<<t1<<','<<t2<<":\n";
//		if(i>=100&&i<=110){
//		cerr<<"Pre: "<<Pre<<'\n';
//		cerr<<"Nxt: "<<Nxt<<'\n';
//		cerr<<"Dif: "<<Dif<<'\n';			
//		}

//		cerr<<Dif_h.h1<<' '<<Dif_h.h2<<": ";
		ll sc03=kkk(Dif_h),tur=turner[sc03];
//		cerr<<sc03<<'\n';
		if(!tur){
			writel(0);puts("");
			continue;
		}
		// To Hash the string "Pre" and "Nxt" and Prev it;
		ll l_p=Pre.length(),l_n=Nxt.length();
		vector<SHash> P_Pre(l_p+10),P_Nxt(l_n+10);
		P_Pre[0]=((SHash){f(Pre[0]),f(Pre[0])});
		P_Nxt[0]=((SHash){f(Nxt[0]),f(Nxt[0])});
		for(ll i=1;i<l_p;i++)
			P_Pre[i].h1=(P_Pre[i-1].h1+K1[i]*f(Pre[i])%Mod1)%Mod1,
			P_Pre[i].h2=(P_Pre[i-1].h2+K2[i]*f(Pre[i])%Mod2)%Mod2;
		for(ll i=1;i<l_n;i++)
			P_Nxt[i].h1=(P_Nxt[i-1].h1+K1[i]*f(Nxt[i])%Mod1)%Mod1,
			P_Nxt[i].h2=(P_Nxt[i-1].h2+K2[i]*f(Nxt[i])%Mod2)%Mod2;		
		ll ans=0;
		for(ll j:Bucket[tur]){//There's a posibility that s1[j]->s2[j] can be the answer.
			if(Dif_h.h1==dif_h[j].h1&&Dif_h.h1==dif_h[j].h1){
				//That'll be pre[j] in Pre && nxt[j] in Nxt
				ll lpre=S[j].pre.length(),lnxt=S[j].nxt.length();
				if(lpre>l_p||lnxt>l_n) continue;
//				if(i>=100&&i<=110)cerr<<"Probable: "<<j<<"\n";
//				cerr<<lpre<<' '<<lnxt<<'\n';
				ll H1_of_Nxt,H2_of_Nxt;
				if(lnxt==0) H1_of_Nxt=0;
				else H1_of_Nxt=P_Nxt[lnxt-1].h1;//Nxt[0...lnxt-1]
				if(lnxt==0) H2_of_Nxt=0; 
				else H2_of_Nxt=P_Nxt[lnxt-1].h2;//Nxt[0...lnxt-1]
				ll H1_of_Pre=P_Pre[l_p-1].h1;//Pre[l_p-lpre...l_p-1]
				if(l_p-lpre>0) H1_of_Pre-=P_Pre[l_p-lpre-1].h1,
								H1_of_Pre+=Mod1,
								H1_of_Pre%=Mod1;
				ll H2_of_Pre=P_Pre[l_p-1].h2;//Pre[l_p-lpre...l_p-1]
				if(l_p-lpre>0) H2_of_Pre-=P_Pre[l_p-lpre-1].h2,
								H2_of_Pre+=Mod2,
								H2_of_Pre%=Mod2;
				ll H1_of_pre=pre_h[j].h1*K1[l_p-lpre]%Mod1,H2_of_pre=pre_h[j].h2*K2[l_p-lpre]%Mod2;
				ll H1_of_nxt=nxt_h[j].h1,H2_of_nxt=nxt_h[j].h2;
//				cerr<<H1_of_Nxt<<' '<<H1_of_Pre<<'\n';
				if((H1_of_pre==H1_of_Pre)&&(H2_of_pre==H2_of_Pre)&&(H1_of_nxt==H1_of_Nxt)&&(H2_of_nxt==H2_of_Nxt))
//				 cerr<<j<<'\n',
				 ans++;
			}
		}
		writel(ans);puts("");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
