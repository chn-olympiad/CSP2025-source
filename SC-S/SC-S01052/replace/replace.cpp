#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=5e6+10;

int n,q;

int ch[2][N][26],cnt[2],f[2][N],lst[2][N];

vector<int> val[2][N];

void add(int id,int opt,string s){
	int len=s.size(),pl=0; s=" "+s;
	for(int i=1;i<=len;i++){
		int num=s[i]-'a';
		if(!ch[opt][pl][num]) ch[opt][pl][num]=++cnt[opt];
		pl=ch[opt][pl][num];
	}
	val[opt][pl].push_back(id);
}

void get_fail(int opt){
	queue<int> q;
	for(int i=0;i<26;i++)
		if(ch[opt][0][i])
			q.push(ch[opt][0][i]);
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0;i<26;i++){
			int v=ch[opt][u][i];
			if(!v){
				ch[opt][u][i]=ch[opt][f[opt][u]][i];
				continue;
			}
			f[opt][v]=ch[opt][f[opt][u]][i];
			lst[opt][v]=val[opt][f[opt][v]].empty()?lst[opt][f[opt][v]]:f[opt][v];
			q.push(v);
		}
	}
}

int lth[N];

int pl[2],l,r;

bool vis[N];

ll calc(int now){
	ll res=0;
	int u=pl[0],v=pl[1];
	while(u){
		for(auto i:val[0][u])
			if(lth[i]>=now-l+1)
				vis[i]=true;
		u=lst[0][u];
	}
	while(v){
		for(auto i:val[1][v])
			if(vis[i]) res++;
		v=lst[1][v];
	}
	u=pl[0];
	while(u){
		for(auto i:val[0][u])
			if(lth[i]>=now-l+1)
				vis[i]=false;
		u=lst[0][u];
	}
	return res;
}

ll query(string t1,string t2){
	if(t1.size()!=t2.size()) return 0;
	ll res=0;
	pl[0]=pl[1]=0;
	int len=t1.size();
	l=1,r=len;
	t1=" "+t1,t2=" "+t2;
	while(t1[l]==t2[l]) l++;
	while(t1[r]==t2[r]) r--;
	for(int i=1;i<=len;i++){
		pl[0]=ch[0][pl[0]][t1[i]-'a'];
		pl[1]=ch[1][pl[1]][t2[i]-'a'];
		if(i>=r) res+=calc(i);
	}
	return res;
}

int main(){
	#ifndef Klein
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		lth[i]=s1.size();
		add(i,0,s1),add(i,1,s2);
	}
	get_fail(0),get_fail(1);
	string t1,t2;
	while(q--){
		cin>>t1>>t2;
		cout<<query(t1,t2)<<'\n';
	}
	return 0;
}
