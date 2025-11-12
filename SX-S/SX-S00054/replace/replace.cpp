#include<bits/stdc++.h>
#define endl '\n'
#define Debug (false)
using namespace std;
typedef long long ll;

inline ll read(){
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
const ll MAXN = 200020;
const ll MAXL=5000020;
ll n,q;
string s[MAXN][2];
string t[MAXN][2];
void th(string &st1, ll l, ll r, string ss2){
	for (ll i=l,p=0; i<=r; i++,p++){
		st1[i]=ss2[p];
	}
	if (Debug) cout<<"正在把"<<st1<<"的"<<l<<"->"<<r<<"替换为"<<ss2<<endl;
}
bool stry(string st1,string st2,string ss1,string ss2){
	//用后两个的替换尝试把第一个转换成第二个
	if (Debug){
		cout<<"正在尝试用"<<ss1<<' '<<ss2<<"把"<<st1<<"->"<<st2<<endl;
	}
	ll p=0;//已经匹配长度
	for (ll i=0; i<ll(st1.size()); i++){
		if (st1[i]==ss1[p]) ++p;
		else p=0;
		if (p==ll(ss1.size())){
			th(st1,i-p+1,i,ss2);//替换
			break;
		}
	}
	if (st1==st2) return true;
	return false;
}
void solve(string ss1,string ss2,ll &ans){
	//尝试解决s1-s2
	if (Debug){
		cout<<"正在尝试解决"<<ss1<<"到"<<ss2<<"的转换"<<endl;
	}
	for (ll i=1; i<=n; i++){
		ans+=stry(ss1,ss2,s[i][0],s[i][1]);
	}
	cout<<ans<<endl;
	ans=0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
// 	变量名注意不要和关键词重复
//	优先拿部分分
	cin>>n>>q;
	if (Debug) cout<<"输入部分"<<endl;
	for (ll i=1; i<=n; i++){
		cin>>s[i][0];
		cin>>s[i][1];
	}
	for (ll j=1; j<=q; j++){
		cin>>t[j][0]>>t[j][1];
	}
	for (ll i=1; i<=q; i++){
		ll ans=0;
		solve(t[i][0],t[i][1],ans);
	}

	return 0;
}
