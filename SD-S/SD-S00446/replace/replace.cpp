//code by JuRuoOIer(Luogu 476093)
//problem:
//expected:
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<deque>
#include<random>
#define ll long long
#define ull unsigned long long
#define lf double
#define ld long double
using namespace std;
void file(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
struct Node{
	ll x,y,z;
};
struct node{
	Node x,y;
};
bool operator <(Node x,Node y){
	return x.x==y.x?(x.y==y.y?x.z<y.z:x.y<y.y):x.x<y.x;
}
bool operator ==(Node x,Node y){
	return x.x==y.x&&x.y==y.y&&x.z==y.z;
}
bool operator <(node x,node y){
	return x.x==y.x?x.y<y.y:x.x<y.x;
}
bool operator ==(node x,node y){
	return x.x==y.x&&x.y==y.y;
}
ll ksm(ll x,ll y,ll mod){
	if(y==0)return 1;
	if(y==1)return x%mod;
	ll tmp=ksm(x,y>>1,mod);
	if(y&1)return tmp*tmp%mod*x%mod;
	return tmp*tmp%mod;
}
ll n,q,H1[3][200010],H2[3][200010],HH1[3][200010],HH2[3][200010],preH1[3][200010],sufH1[3][200010],preH2[3][200010],sufH2[3][200010],h1[3],h2[3];
const ll m[3]={998244353,1000000007,19260817};
string s1[200010],s2[200010],t1,t2;
map<node,vector<node> > pre;
map<node,ll> suf;
int main(){
	file();
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		ll f=0,l=-1;
		for(int j=0;j<s1[i].length();j++){
			H1[0][i]*=31;H1[0][i]+=s1[i][j]-'a'+1;H1[0][i]%=m[0];
			H1[1][i]*=31;H1[1][i]+=s1[i][j]-'a'+1;H1[1][i]%=m[1];
			H1[2][i]*=31;H1[2][i]+=s1[i][j]-'a'+1;H1[2][i]%=m[2];
			H2[0][i]*=31;H2[0][i]+=s2[i][j]-'a'+1;H2[0][i]%=m[0];
			H2[1][i]*=31;H2[1][i]+=s2[i][j]-'a'+1;H2[1][i]%=m[1];
			H2[2][i]*=31;H2[2][i]+=s2[i][j]-'a'+1;H2[2][i]%=m[2];
			if(s1[i][j]==s2[i][j]){
				f+=(f==j);
			}
			else{
				l=j;
			}
		}
		for(int j=f;j<=l;j++){
			HH1[0][i]*=31;HH1[0][i]+=s1[i][j]-'a'+1;HH1[0][i]%=m[0];
			HH1[1][i]*=31;HH1[1][i]+=s1[i][j]-'a'+1;HH1[1][i]%=m[1];
			HH1[2][i]*=31;HH1[2][i]+=s1[i][j]-'a'+1;HH1[2][i]%=m[2];
			HH2[0][i]*=31;HH2[0][i]+=s2[i][j]-'a'+1;HH2[0][i]%=m[0];
			HH2[1][i]*=31;HH2[1][i]+=s2[i][j]-'a'+1;HH2[1][i]%=m[1];
			HH2[2][i]*=31;HH2[2][i]+=s2[i][j]-'a'+1;HH2[2][i]%=m[2];
		}
		for(int j=l;j>=0;j--){
			preH1[0][i]*=31;preH1[0][i]+=s1[i][j]-'a'+1;preH1[0][i]%=m[0];
			preH1[1][i]*=31;preH1[1][i]+=s1[i][j]-'a'+1;preH1[1][i]%=m[1];
			preH1[2][i]*=31;preH1[2][i]+=s1[i][j]-'a'+1;preH1[2][i]%=m[2];
			preH2[0][i]*=31;preH2[0][i]+=s2[i][j]-'a'+1;preH2[0][i]%=m[0];
			preH2[1][i]*=31;preH2[1][i]+=s2[i][j]-'a'+1;preH2[1][i]%=m[1];
			preH2[2][i]*=31;preH2[2][i]+=s2[i][j]-'a'+1;preH2[2][i]%=m[2];
		}
		for(int j=f;j<s1[i].length();j++){
			sufH1[0][i]*=31;sufH1[0][i]+=s1[i][j]-'a'+1;sufH1[0][i]%=m[0];
			sufH1[1][i]*=31;sufH1[1][i]+=s1[i][j]-'a'+1;sufH1[1][i]%=m[1];
			sufH1[2][i]*=31;sufH1[2][i]+=s1[i][j]-'a'+1;sufH1[2][i]%=m[2];
			sufH2[0][i]*=31;sufH2[0][i]+=s2[i][j]-'a'+1;sufH2[0][i]%=m[0];
			sufH2[1][i]*=31;sufH2[1][i]+=s2[i][j]-'a'+1;sufH2[1][i]%=m[1];
			sufH2[2][i]*=31;sufH2[2][i]+=s2[i][j]-'a'+1;sufH2[2][i]%=m[2];
		}
		pre[{{sufH1[0][i],sufH1[1][i],sufH1[2][i]},{sufH2[0][i],sufH2[1][i],sufH2[2][i]}}].push_back({{preH1[0][i],preH1[1][i],preH1[2][i]},{preH2[0][i],preH2[1][i],preH2[2][i]}});
	}
	while(q--){
		cin>>t1>>t2;
		h1[0]=h1[1]=h1[2]=h2[0]=h2[1]=h2[2]=0;
//		ll b[3]={ksm(31,s1[i].length(),m[0]),ksm(31,s1[i].length(),m[1]),ksm(31,s1[i].length(),m[2])};
		ll f=0,l=-1;
		for(int i=0;i<t1.length();i++){
			if(t1[i]==t2[i]){
				f+=(f==i);
			}
			else{
				l=i;
			}
		}
		suf.clear();
		for(int i=f;i<t1.size();i++){
			h1[0]*=31;h1[0]+=t1[i]-'a'+1;h1[0]%=m[0];
			h1[1]*=31;h1[1]+=t1[i]-'a'+1;h1[1]%=m[1];
			h1[2]*=31;h1[2]+=t1[i]-'a'+1;h1[2]%=m[2];
			h2[0]*=31;h2[0]+=t2[i]-'a'+1;h2[0]%=m[0];
			h2[1]*=31;h2[1]+=t2[i]-'a'+1;h2[1]%=m[1];
			h2[2]*=31;h2[2]+=t2[i]-'a'+1;h2[2]%=m[2];
			if(i>=l){
				vector<node> tmp=pre[{{h1[0],h1[1],h1[2]},{h2[0],h2[1],h2[2]}}];
				for(int j=0;j<tmp.size();j++){
					suf[tmp[j]]++;
				}
			}
		}
		h1[0]=h1[1]=h1[2]=h2[0]=h2[1]=h2[2]=0;
		ll ans=0;
		for(int i=l;i>=0;i--){
			h1[0]*=31;h1[0]+=t1[i]-'a'+1;h1[0]%=m[0];
			h1[1]*=31;h1[1]+=t1[i]-'a'+1;h1[1]%=m[1];
			h1[2]*=31;h1[2]+=t1[i]-'a'+1;h1[2]%=m[2];
			h2[0]*=31;h2[0]+=t2[i]-'a'+1;h2[0]%=m[0];
			h2[1]*=31;h2[1]+=t2[i]-'a'+1;h2[1]%=m[1];
			h2[2]*=31;h2[2]+=t2[i]-'a'+1;h2[2]%=m[2];
			if(i<=f)ans+=suf[{{h1[0],h1[1],h1[2]},{h2[0],h2[1],h2[2]}}];
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
才记起 副本的原则最绝情
从未有 相逢不相忘的心
我被封存在数据里 从前世苏醒
想挣开岁月 那虚无的侵袭
自定义是我 未命名是你
无关于轮回的密令
你我明知在故事里 梦醒就分离
明知相守模式尚不可沉浸
重置前的我 忘却前的你
还在等那抹黎明

可以祝我 rp++ 吗，摩柯？ 
*/ 
