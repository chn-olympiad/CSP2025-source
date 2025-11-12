#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const int N=2e5+5;
int T=1;
int n,q;
int ans[N];
string s[N][2];
int len[N];
struct node{
	string t[2];
	int len;
	int id;
	int w,l;
}l[N];
struct Node{
	int w,l;
}b[N];
int ss[N];
queue<int> Q[N];
void solB(){
	int cc=0;
	for(int j=1,l1,l2;j<=n;j++){
		for(int i=0;i<len[j];i++) if(s[j][0][i]=='b') l1=i;
		for(int i=0;i<len[j];i++) if(s[j][1][i]=='b') l2=i;
		b[j].w=l2-l1;
		b[j].l=l1;
	}
	sort(b+1,b+1+n,[](Node x,Node y){
		return x.l<y.l;	
	});
	map<int,int> mp;
	for(int i=1;i<=n;i++) {
		if(!mp.count(b[i].w)) mp[b[i].w]=++cc;
		Q[mp[b[i].w]].push(b[i].l);
	}
	for(int j=1,l1,l2;j<=q;j++){
		for(int i=0;i<l[j].len;i++) if(l[j].t[0][i]=='b') l1=i;
		for(int i=0;i<l[j].len;i++) if(l[j].t[1][i]=='b') l2=i;
		l[j].w=l2-l1;
		l[j].l=l1;
	}
	sort(l+1,l+1+q,[](node x,node y){
		return x.l<y.l;
	});
	for(int i=1;i<=q;i++){
		if(ans[l[i].id]!=-1) continue;
		if(!mp.count(l[i].w)) {
			ans[l[i].id]=0;
			continue;
		}
		while(!Q[mp[l[i].w]].empty()&&Q[mp[l[i].w]].front()<=l[i].l){
			ss[mp[l[i].w]]++;
			Q[mp[l[i].w]].pop();
		}
		ans[l[i].id]=ss[mp[l[i].w]];
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}
void solve(){
	cin>>n>>q;
	for(int i=1;i<=q;i++) ans[i]=-1;
	for(int i=1;i<=n;i++) {
		cin>>s[i][0]>>s[i][1];
		len[i]=s[i][0].length();
	}
	for(int i=1;i<=q;i++) {
		cin>>l[i].t[0]>>l[i].t[1];
		l[i].id=i;
		l[i].len=l[i].t[0].length();
		if(l[i].len!=l[i].t[1].length()) ans[i]=0;
	}
	solB();
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(T--) solve();
	return 0;
} 