#include<bits/stdc++.h>

#define _vc_(_6,_5,_4,_3,_2,_1,_,...) _
#define _vc(a...) _vc_(a,6,5,4,3,2,1)
#define _ct_(a,b) a##b
#define _ct(a,b) _ct_(a,b)
#define deb1(a) <<#a<<"="<<(a)<<"; "
#define deb2(a,b...) deb1(a)deb1(b)
#define deb3(a,b...) deb1(a)deb2(b)
#define deb4(a,b...) deb1(a)deb3(b)
#define deb5(a,b...) deb1(a)deb4(b)
#define deb6(a,b...) deb1(a)deb5(b)
#define deb(a...) cerr<<string(_dep*3,' ')<<"deb"<<__LINE__<<"|:" _ct(deb,_vc(a)) (a) <<endl
unsigned _dep;

using namespace std;

const int maxL1=5e6+10;



//struct qry{
//	int nxt,id;
//}edge[maxL1/2];int ec;

//int ans[10+(int)2e5];

struct node{
	int p,s[26],ep_s,las_ep,ans,len;
}t[maxL1];int tot;


int n,Q;
char S[maxL1],T[maxL1];

int q[maxL1],hd,tl;

signed main(){
//	deb((sizeof t + sizeof S + sizeof T + sizeof q) >> 20); 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>Q;
	for(int _=1;_<=n;++_){
		cin>>S>>T;int len=strlen(S);
	
		int diff_p=0;
		while(diff_p<len && S[diff_p] == T[diff_p]) ++ diff_p;
		
		int u=0;
		for(int i=0;i<len;++i){
			for(char c_o:{S[i],T[i]}){
				int c=c_o-'a';
				if(!t[u].s[c])t[t[u].s[c]=++tot].len = i+1;
				u=t[u].s[c];
			}
		}
		
//		deb(_,S,T,u);
		
		++t[u].ep_s;
		t[u].ans=diff_p;
	}
	
	hd=1,tl=0;
	for(int i=0;i<26;++i)if(t[0].s[i])q[++tl]=t[0].s[i];
	while(hd<=tl){
		int u=q[hd++];
		t[u].las_ep=(t[u].ep_s?u:t[u].p[t].las_ep);
		for(int i=0;i<26;++i){
			if(t[u].s[i]){
				t[u].s[i][t].p=t[u].p[t].s[i];
				q[++tl]=t[u].s[i];
			}else t[u].s[i]=t[u].p[t].s[i];
		}
	}
	
	for(int i=1;i<=tot;++i){
//		t[i].las_ep=(t[i].ep_s?i:t[i].p[t].las_ep);
//		deb(i,t[i].las_ep);
	
		if(t[i].ep_s){
			int diff_p=t[i].ans;t[i].ans=0;
			
			int u=i;
			while(u && t[i].len - t[u].len <= diff_p )
				t[i].ans += t[u].ep_s,u=t[u].p;
		}
	}
	
	for(int _=1;_<=Q;++_){
		cin>>S>>T;int len=strlen(S);
		if(strlen(T) != len){
			cout<<"0\n";continue;
		}
		
		int diff_p=0,diff_s=len-1;
		while(diff_p<len && S[diff_p] == T[diff_p]) ++ diff_p;
		while(diff_s>=0 && S[diff_s] == T[diff_s]) -- diff_s;
		
		long long ans=0;
		
		int u=0;
		for(int i=0;i<len;++i){
			u=t[u].s[S[i]-'a'][t].s[T[i]-'a'];
			
//			deb(i,u,t[u].len,t[u].las_ep);
			
			int cur=t[u].las_ep;
			if(i-t[cur].len < diff_p && diff_s <= i){
				ans += t[cur].ans;
//				deb(i, t[cur].ans); 
			}
//				add_edge(t[cur].fir_t,_);
		}
		cout<<ans<<'\n';
	}
	
	
}

