#include <bits/stdc++.h>
#define int long long
using namespace std;
const int modd=1000000000000037;
const int maxn=2e5+10;
const int MX=5e6+10;
int n,m,tot,now,ch[MX][26],rt[MX],ans,ls[maxn*64],rs[maxn*64],sum[maxn*64],idd,len,L,R;
string s[maxn][2],t[2];
map<int,int>qi;
unsigned long long hsh1,hsh2;
inline void add(int &id,int l,int r,int q){
	if(!id){
		idd++;
		id=idd;
	}
	if(l==r){
		sum[id]++;
		return;
	}
	int mid=(l+r)>>1;
	if(q<=mid){
		add(ls[id],l,mid,q);
	}
	else{
		add(rs[id],mid+1,r,q);
	}
	return;
}
inline int merge(int q,int w){
	if(!q||!w){
		return q+w;
	}
	ls[q]=merge(ls[q],ls[w]);
	rs[q]=merge(rs[q],rs[w]);
	sum[q]=sum[q]+sum[w];
	return q;
}
inline int query(int id,int l,int r,int q){
	if(l==r){
		return sum[id];
	}
	int mid=(l+r)>>1;
	if(q<=mid){
		return query(ls[id],l,mid,q);
	}
	else{
		return query(rs[id],mid+1,r,q);
	}
}
inline void dfs(int q){
	for(int i=0;i<26;i++){
		if(ch[q][i]){
			rt[ch[q][i]]=merge(rt[ch[q][i]],rt[q]);
			dfs(ch[q][i]);
		}
	}
	return;
}
inline void init(){
	for(auto v:qi){
		if(v.first&&v.second){
			now=v.second;
			dfs(now);
		}
	}
	return;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		len=s[i][0].size();
		L=len,R=0;
		for(int j=0;j<len;j++){
			if(s[i][0][j]!=s[i][1][j]){
				L=min(L,j);
				R=max(R,j);
			}
		}
		if(L<=R){
			hsh1=0;
			for(int j=L;j<=R;j++){
				hsh1=(hsh1*131+s[i][0][j]-'a'+1)%modd;
				hsh1=(hsh1*131+s[i][1][j]-'a'+1)%modd;
			}
			hsh2=0;
			for(int j=R+1;j<len;j++){
				hsh2=(hsh2*131+s[i][0][j]-'a'+1)%modd;
			}
			if(!qi[hsh1]){
				tot++;
				qi[hsh1]=tot;
			}
			now=qi[hsh1];
			for(int j=L-1;j>=0;j--){
				if(!ch[now][s[i][0][j]-'a']){
					tot++;
					ch[now][s[i][0][j]-'a']=tot;
				}
				now=ch[now][s[i][0][j]-'a'];
			}
			add(rt[now],0,modd,hsh2);
		}
	}
	init();
	while(m--){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<0<<'\n';
			continue;
		}
		len=t[0].size();
		L=len,R=0;
		for(int i=0;i<len;i++){
			if(t[0][i]!=t[1][i]){
				L=min(L,i);
				R=max(R,i);
			}
		}
		ans=0;
		hsh1=0;
		for(int i=L;i<=R;i++){
			hsh1=(hsh1*131+t[0][i]-'a'+1)%modd;
			hsh1=(hsh1*131+t[1][i]-'a'+1)%modd;
		}
		now=qi[hsh1];
		if(now){
			for(int i=L-1;i>=0;i--){
				if(ch[now][t[0][i]-'a']){
					now=ch[now][t[0][i]-'a'];
				}
				else{
					break;
				}
			}
			hsh2=0;
			ans+=query(rt[now],0,modd,hsh2);
			for(int i=R+1;i<len;i++){
				hsh2=(hsh2*131+t[0][i]-'a'+1)%modd;
				ans+=query(rt[now],0,modd,hsh2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
