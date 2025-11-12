#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=993244853;
int sum[6000010],son[6000010][28],fail[6000010],len[200010],lb[200010],rb[200010],tot,root[200010],coidx;
char s[5000010],ss[5000010];
void ins(int &p,int id,int dep){
	if(!p)p=++tot;
	if(dep==len[id])return sum[p]++,void();
	ins(son[p][s[dep+1]-'a'],id,dep+1);
}
void bfs(int id){
	queue<int> q;
	for(int i=0;i<=26;i++){
		if(!son[root[id]][i])son[root[id]][i]=root[id];
		else q.push(son[root[id]][i]);
		fail[son[root[id]][i]]=root[id];
	}
	fail[root[id]]=root[id];
	while(q.size()){
		int t=q.front();q.pop();
		sum[t]+=sum[fail[t]];
		for(int i=0;i<=26;i++){
			if(son[t][i]){
				fail[son[t][i]]=son[fail[t]][i];
				q.push(son[t][i]);
			}
			else son[t][i]=son[fail[t]][i];
		}
	}
}
int query(int id,int lenn){
	int cur=root[id],res=0;
	for(int i=1;i<=lenn;i++){
		cur=son[cur][s[i]-'a'];
		res+=sum[cur];
	}
	return res;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		scanf("%s%s",s+1,ss+1);
		len[i]=strlen(s+1);
		for(int j=1;j<=len[i];j++)if(s[j]^ss[j]){
			if(!lb[i])lb[i]=j;
			rb[i]=j;
		}
		if(!lb[i])continue;
		int hh=0;
		for(int j=lb[i];j<=rb[i];j++)hh=(hh*120921+s[j]*131+ss[j])%mod;
		s[lb[i]]=ss[lb[i]]='z'+1;
		for(int j=rb[i]+1;j<=len[i];j++)s[j-rb[i]+lb[i]]=s[j],ss[j-rb[i]+lb[i]]=ss[j];
		len[i]-=rb[i]-lb[i];
		if(!mp[hh])mp[hh]=++coidx;
		ins(root[mp[hh]],i,0);
	}
	for(int i=1;i<=coidx;i++)bfs(i);
	while(m--){
		scanf("%s%s",s+1,ss+1);
		int lenn=strlen(s+1),lenn2=strlen(ss+1),ll=0,rr=0;
		if(lenn^lenn2){
			puts("0");
			continue;
		}
		for(int j=1;j<=lenn;j++)if(s[j]^ss[j]){
			if(!ll)ll=j;
			rr=j;
		}
		int hh=0;
		for(int j=ll;j<=rr;j++)hh=(hh*120921+s[j]*131+ss[j])%mod;
		if(!mp[hh]){
			puts("0");
			continue;
		}
		s[ll]='z'+1;
		for(int j=rr+1;j<=lenn;j++)s[j-rr+ll]=s[j];
		lenn-=rr-ll;
		printf("%lld\n",query(mp[hh],lenn));
	}
}
