#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll base=31;
constexpr ll mod=998244353;

constexpr int maxn=2e5;
constexpr int maxL=5e6;

struct nodeout{
	int c[26];
	vector<pair<int,string>> quary;
	vector<string> s2;
	int root;
};

int answer[maxn+5];
nodeout trie1[maxL+5];
int cnt=0;
void Insert(string s1,string s2,int root){
	#ifdef debug
	cout<<root<<":\n";
	#endif
	for(auto i:s1){
		#ifdef debug
		cout<<s1<<" "<<s2<<" "<<root<<":"<<i-'a'<<"\n";
		#endif
		if(trie1[root].c[i-'a']==0){
			cnt++;
			trie1[root].c[i-'a']=cnt;
			#ifdef debug
			cout<<root<<" "<<trie1[root].c[i-'a']<<":"<<i-'a'<<"\n";
			#endif
		}
		root=trie1[root].c[i-'a'];
	}
	#ifdef debug
	cout<<s1<<" "<<s2<<" "<<root<<"\n";
	#endif
	trie1[root].s2.push_back(s2);
	#ifdef debug
	cout<<root<<" Insert "<<s2<<"\n";
	#endif
}

void Push(int root,string s1,string s2,int num){
	for(auto i:s1){
		if(trie1[root].c[i-'a']==0){
			break;
		}
		root=trie1[root].c[i-'a'];
	}
	trie1[root].quary.push_back(make_pair(num,s2));
}

struct nodein{
	int c[26];
	int sze;
};

nodein trie2[maxL+5];
int cnt2=0;

void Insert2(int root,string s){
	#ifdef debug
	cout<<"Insertsec "<<root<<" "<<s<<"\n";
	#endif
	for(auto i:s){
		if(trie2[root].c[i-'a']==0){
			trie2[root].c[i-'a']=++cnt2;
			#ifdef debug
			cout<<root<<" "<<cnt2<<"\n";
			#endif
		}
		root=trie2[root].c[i-'a'];
	}
	trie2[root].sze++;
	#ifdef debug
	cout<<"+ "<<root<<"\n";
	#endif
}

void merge(int x,int y){
//	cout<<"Merge "<<x<<" "<<y<<"\n";
	trie2[x].sze+=trie2[y].sze;
	for(int i=0;i<26;i++){
		int& c1=trie2[x].c[i];
		int& c2=trie2[y].c[i];
		if(c1!=0&&c2!=0){
			merge(c1,c2);
		}
		else if(c1!=0&&c2==0){
			continue;
		}
		else if(c1==0&&c2!=0){
			c1=c2;
		}
		else{
			continue;
		}
	}
//	cout<<trie2[x].sze<<" "<<trie2[y].sze<<"\n";
}

int quary(int root,string s){
	#ifdef debug
	cout<<"Q "<<root<<" "<<s<<"\n";
	#endif
	int ret=0;
	for(auto i:s){
		ret+=trie2[root].sze;
		if(trie2[root].c[i-'a']==0){
			return ret;
		}
		root=trie2[root].c[i-'a'];
	}
	ret+=trie2[root].sze;
	return ret;
}

void dfs(int root,int fa){
	trie1[root].root=++cnt2;
//	cout<<root<<":"<<trie1[root].root<<"\n";
	if(fa!=0){
		merge(trie1[root].root,trie1[fa].root);
	}
	for(auto i:trie1[root].s2){
		Insert2(trie1[root].root,i);
	}
	for(auto i:trie1[root].quary){
		answer[i.first]+=quary(trie1[root].root,i.second);
	}
	for(int i=0;i<26;i++){
		if(trie1[root].c[i]!=0){
			dfs(trie1[root].c[i],root);
		}
	}
}

ll hsh(string& s,int l,int r){
	ll ans=0;
	for(int i=l;i<=r;i++){
		ans=ans*base%mod;
		ans+=s[i];
		if(ans>=mod)
			ans-=mod;
	}
	return ans;
} 

map<pair<int,int>,int> rts;
int n,q;

void bf(){
	string s[n+1][2];
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		//for(int j=0;j<=1;j++){
		//	s[i][j].init();
		//}
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		//t1.init();
		//t2.init();
		if(t1.length()!=t2.length()){
			cout<<0<<"\n";
			continue;
		}
		int ans=0;
		for(int ii=1;ii<=n;ii++){
			for(int pos=0;pos+s[ii][0].size()-1<t1.size();pos++){
			//	cout<<ii<<" "<<pos<<"\n";
				for(int i=0;i<pos;i++){
					if(t1[i]!=t2[i]){
						goto label;
					}
				}
				for(int i=pos,j=0;j<s[ii][0].size();j++,i++){
					if(t1[i]!=s[ii][0][j]||t2[i]!=s[ii][1][j]){
						goto label;
					}
				}
				for(int i=pos+s[ii][0].size();i<t1.size();i++){
					if(t1[i]!=t2[i]){
						goto label;
					}
				}
				ans++;
				label:;
			}
		}
		cout<<ans<<"\n";
	}
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>q;
	if(n<=100){
		bf();
		return 0;
	}
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		string ll,rr;
		int l=0,r=s1.size()-1;
		while(s1[l]==s2[l]){
			l++;
		}
		while(s1[r]==s2[r]){
			r--;
		}
		int p1=hsh(s1,l,r),p2=hsh(s2,l,r);
		int& rt=rts[make_pair(p1,p2)];
		//cout<<p1<<" "<<p2<<"\n";
		if(rt==0){
			rt=++cnt;
		}
		for(int i=l-1;i>=0;i--){
			ll.push_back(s1[i]);
		}
		for(int i=r+1;i<s1.size();i++){
			rr.push_back(s1[i]);
		}
		Insert(ll,rr,rt);
	//	cout<<i<<" all: "<<ll<<" "<<rr<<" "<<rt<<"\n";
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			continue;
		}
		string ll,rr;
		int l=0,r=s1.size()-1;
		while(s1[l]==s2[l]){
			l++;
		}
		while(s1[r]==s2[r]){
			r--;
		}
		int p1=hsh(s1,l,r),p2=hsh(s2,l,r);
		if(!rts.count(make_pair(p1,p2))){
			continue;
		}
		int& rt=rts[make_pair(p1,p2)];
		if(rt==0){
			rt=++cnt;
		}
		for(int i=l-1;i>=0;i--){
			ll.push_back(s1[i]);
		}
		for(int i=r+1;i<s1.size();i++){
			rr.push_back(s1[i]);
		}
		Push(rt,ll,rr,i);
	}
	for(auto i:rts){
		dfs(i.second,0);
	}
	for(int i=1;i<=q;i++){
		cout<<answer[i]<<"\n";
	}
}
