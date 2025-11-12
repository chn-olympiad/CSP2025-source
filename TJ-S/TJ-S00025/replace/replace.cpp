#include<bits/stdc++.h>
//#define int long long
using namespace std;
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back
#define ep emplace
#define Endl putchar('\n')
#define Space putchar(' ')
typedef long long ll;
using pii=pair<int,int>;
const int mod=998244353,inf=0x3f3f3f3f;
const ll Inf=0x3f3f3f3f3f3f3f3f;
template<typename T> inline void read(T &s){
	s=0;int c=getchar();bool f=0;
	while(!isdigit(c))f^=(c=='-'),c=getchar();
	while(isdigit(c))s=(s<<1)+(s<<3)+(c^48),c=getchar();
}
template<typename T> inline void write(T x){
	static int St[40],Top=0;
	if(x<0)putchar('-'),x=-x;
	do St[++Top]=x%10,x/=10; while(x);
	while(Top)putchar(St[Top--]^48);
}
void read(char &c){do c=getchar(); while(isspace(c));}
template<typename type,typename... T> inline void read(type &x,T&...y){read(x);read(y...);}
struct node{
	int x,y,z;
	bool operator < (const node& o)const{
		if(x!=o.x)return x<o.x;
		if(y!=o.y)return y<o.y;
		return z<o.z;
	}
};
map<node,int> son;
map<int,int> num;
int idx;
void insert(const string& s1,const string& s2){
	int p=0;
	for(int i=0;i<s1.size();i++){
		int &s=son[{p,s1[i]-'a',s2[i]-'a'}];
		if(!s)s=++idx;
		p=s;
	}
	num[p]++;
}
int query(const string& s1,const string& s2){
	int p=0;
	for(int i=0;i<s1.size();i++){
		int &s=son[{p,s1[i]-'a',s2[i]-'a'}];
//		cout<<p<<" "<<s<<" "<<s1[i]-'a'<<" "<<s2[i]-'a'<<endl;
		if(!s)return 0;
		p=s;
	}
//	cout<<p<<" "<<num[p]<<endl;
	return num[p];
}
struct xxx{
	string s1,s2;
	int id;
	bool operator < (const xxx& o)const{return s1.size()<o.s1.size();}
	bool operator <= (const xxx& o)const{return s1.size()<=o.s1.size();}
};
void insert(const xxx& s){
	string s1=s.s1,s2=s.s2;
//	cout<<s1<<" "<<s2<<endl;
	if(s1==s2)return;
	int l=0,r=s1.size()-1;
	while(s1[l]==s2[l])l++;
	while(s1[r]==s2[r])r--;
	insert(s1.substr(l,r-l+1),s2.substr(l,r-l+1));
}
int query(const xxx& s){
	string s1=s.s1,s2=s.s2;
//	cout<<s1<<" "<<s2<<endl;
	int l=0,r=s1.size()-1;
	while(s1[l]==s2[l])l++;
	while(s1[r]==s2[r])r--;
//	cout<<l<<" "<<r<<endl;
	return query(s1.substr(l,r-l+1),s2.substr(l,r-l+1));
}
void solve(){
	int n,m;cin>>n>>m;
	vector<int> ans(m+1);
	vector<xxx> s(n),t(m);
	for(int i=0;i<n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	sort(s.begin(),s.end());
	for(int i=0;i<m;i++){
		cin>>t[i].s1>>t[i].s2;t[i].id=i;
	}
	sort(t.begin(),t.end());
	for(int i=0,j=0;j<m;j++){
		if(t[j].s1.size()!=t[j].s2.size())continue;
		while(i<n&&s[i]<=t[j])insert(s[i++]);
		ans[t[j].id]=query(t[j]);
//		cout<<i<<endl;
//		for(auto x:num)cout<<x.fi<<" "<<x.se<<endl;
	}
	for(int i=0;i<m;i++)cout<<ans[i]<<"\n";
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int T=1;//read(T);
	while(T--){
		solve();
	}
	return 0;
}

