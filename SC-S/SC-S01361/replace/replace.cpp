#include<bits/stdc++.h>
#define ll long long
#define mod 9982450517710471
using namespace std;
struct node{
	ll fail;
	int ed[27];
	ll cnt;
	node(){
		cnt=0;
		for(ll i=0;i<27;i++){
			ed[i]=-1;
		}
	}
}tree[6000006];
ll trsz=0;
ll root[1000006];
string ins;
void newnode(ll from,ll dir){
	ll cur=trsz;
	trsz++;
	tree[from].ed[dir]=cur;
	return;
}
void add(ll cur,ll dep){
	if(dep==ins.size()){
		tree[cur].cnt++;
		return;
	}
	if(ins[dep]=='#'){
		if(tree[cur].ed[26]==-1){
			newnode(cur,26);
		}
		add(tree[cur].ed[26],dep+1);
	}
	else{
		ll op=ins[dep]-'a';
		if(tree[cur].ed[op]==-1){
			newnode(cur,op);
		}
		add(tree[cur].ed[op],dep+1);
	}
}
void getfail(ll cur,ll fa,ll dir,ll root){
	ll f=tree[fa].fail;
//	cout<<"searchfail"<<root<<"\n";
	while(f!=root&&tree[f].ed[dir]==-1){
		f=tree[f].fail;
	//	cout<<f<<"\n";
	}
//	cout<<"foundfail\n";
	if(f!=root||(fa!=root&&tree[f].ed[dir]!=-1)){
		tree[cur].fail=tree[f].ed[dir];
	}
	else{
		tree[cur].fail=root;
	}
}
int que[10000010];
ll hd=0,tl=-1;
void bfs(ll root){
	//cout<<"inbfs";
	tree[root].fail=root;
	for(ll i=0;i<27;i++){
		if(tree[root].ed[i]!=-1){
			getfail(tree[root].ed[i],root,i,root);
		}
	}
//	cout<<"okmed";
	hd=0;
	tl=0;
	que[0]=root;
	while(hd<=tl){
		ll h=que[hd];
		hd++;
		if(tree[h].fail!=root)tree[h].cnt+=tree[tree[h].fail].cnt;
		for(ll i=0;i<27;i++){
			if(tree[h].ed[i]!=-1){
				getfail(tree[h].ed[i],h,i,root);
				que[++tl]=tree[h].ed[i];
			}
		}
	}
//	cout<<"outbfs\n";
}
ll ans=0;
void getans(ll cur,ll dep,ll root){
	//cout<<dep<<"\n"; 
	if(cur!=root) ans+=tree[cur].cnt;
	if(dep==ins.size()) return;
	ll dir;
	if(ins[dep]=='#') dir=26;
	else dir=ins[dep]-'a';
	while(cur!=root&&tree[cur].ed[dir]==-1){
		cur=tree[cur].fail;
	}
	if(tree[cur].ed[dir]!=-1){
		getans(tree[cur].ed[dir],dep+1,root);
	}
	else{
		getans(cur,dep+1,root);
	}
}
struct chan{
	ll x,y;
	ll len;
	chan(){
		x=0;
		y=0;
		len=0;
	}
	bool operator <(chan b) const{
		if(x!=b.x) return x<b.x;
		if(y!=b.y) return y<b.y;
		return len<b.len;
	}
};
map<chan,ll> mp;vector<ll> rts;
ll addcnt=0;
void adds(){
	string s1,s2;
	cin>>s1>>s2;
	if(s1==s2) return;
	
	string sbg,sed,smed;
	ll breakl,breakr;
	for(ll i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			breakl=i;
			break;
		}
		sbg+=s1[i];
	}
	for(ll i=s1.size()-1;i>=0;i--){
		if(s1[i]!=s2[i]){
			breakr=i;
			break;
		}
		sed+=s1[i];
	}
	reverse(sed.begin(),sed.end());
	sbg=sbg+'#'+sed;
//	cout<<sbg<<"\n";
	chan tmp;
	tmp.len=breakr-breakl+1;
	for(ll i=breakl;i<=breakr;i++){
		tmp.x*=29;
		tmp.x%=mod;
		tmp.x+=s1[i]-'a'+1;
		tmp.x%=mod;
		tmp.y*=29;
		tmp.y%=mod;
		tmp.y+=s2[i]-'a'+1;
		tmp.y%=mod;
	}
	//cout<<mp.size()<<"\n";
	if(mp.count(tmp)){
		ins=sbg;
		add(mp[tmp],0);
	}
	else{
		mp[tmp]=trsz;
		rts.push_back(trsz);
		trsz++;
		ins=sbg;
		add(mp[tmp],0);
	}
}

void answer(){
	ans=0;
 	string s1,s2;
	cin>>s1>>s2;
	if(s1==s2) return;
	string sbg,sed,smed;
	ll breakl,breakr;
	for(ll i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			breakl=i;
			break;
		}
		sbg+=s1[i];
	}
	for(ll i=s1.size()-1;i>=0;i--){
		if(s1[i]!=s2[i]){
			breakr=i;
			break;
		}
		sed+=s1[i];
	}
	reverse(sed.begin(),sed.end());
	sbg=sbg+'#'+sed;
//	cout<<sbg<<"\n";
	chan tmp;
	tmp.len=breakr-breakl+1;
	for(ll i=breakl;i<=breakr;i++){
		tmp.x*=29;
		tmp.x%=mod;
		tmp.x+=s1[i]-'a'+1;
		tmp.x%=mod;
		tmp.y*=29;
		tmp.y%=mod;
		tmp.y+=s2[i]-'a'+1;
		tmp.y%=mod;
	}
	if(mp.count(tmp)){
		ins=sbg;
		getans(mp[tmp],0,mp[tmp]);
		cout<<ans<<"\n";
	}
	else{
		cout<<0<<"\n";
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,q;
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		adds();
	}
	for(ll i=0;i<mp.size();i++){
		bfs(rts[i]);
	}
	for(ll i=1;i<=q;i++){
		answer();
	}
	return 0;
}