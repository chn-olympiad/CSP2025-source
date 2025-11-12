#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int base=2333;
int read(){
	char c=getchar();int x=0;bool f=0;
	while(c>'9'||c<'0'){
		if(c=='-')f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	if(f)return -x;
	return x;
}
int n,q,id;
map<pair<ull,ull>,int> rt;
map<pair<int,ull>,int> sum;
string s1,s2;
struct TH{
	int son[5000005][26],id;
	map<ull,int> mp[5000005];
	void insert(int &p,int w,ull v){
		if(!p)p=++id;
		if(w<0){
			mp[p][v]++;
			return;
		}
		insert(son[p][s1[w]-'a'],w-1,v);
	}
	int query(int p,int w,int l,int r){
		if(!p)return 0;
		int ans=0;ull h=0;
		if(mp[p].find(0)!=mp[p].end())ans+=mp[p][0];
		for(int i=l;i<=r;i++){
			h=h*base+s1[i];
			if(mp[p].find(h)!=mp[p].end())ans+=mp[p][h];
		}
		if(w<0)return ans;
		return ans+query(son[p][s1[w]-'a'],w-1,l,r);
	}
}tp;
string reads(){
	string x;
	char c=getchar();
	while(c>'z'||c<'a')c=getchar();
	while(c>='a'&&c<='z')x+=c,c=getchar();
	return x;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		s1=reads(),s2=reads();
		int l=-1,r=0;int len=s1.size();
		for(int i=0;i<len;i++)if(s1[i]!=s2[i]){
			if(l==-1)l=i;
			r=i;
		}
		ull h1=0,h2=0,h3=0;
		for(int i=l;i<=r;i++)h1=h1*base+s1[i],h2=h2*base+s2[i];
		for(int i=r+1;i<len;i++)h3=h3*base+s1[i];
		tp.insert(rt[make_pair(h1,h2)],l-1,h3);
	}
	for(int i=1;i<=q;i++){
		s1=reads(),s2=reads();
		int l=-1,r=0;int len=s1.size();
		for(int i=0;i<len;i++)if(s1[i]!=s2[i]){
			if(l==-1)l=i;
			r=i;
		}
		ull h1=0,h2=0;
		for(int i=l;i<=r;i++)h1=h1*base+s1[i],h2=h2*base+s2[i];
		printf("%d\n",tp.query(rt[make_pair(h1,h2)],l-1,r+1,s1.size()-1));
	}
	return 0;
}
