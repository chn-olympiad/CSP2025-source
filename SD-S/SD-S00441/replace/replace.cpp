#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define up(_i,_l,_r) for(auto _i=_l;_i<=_r;++_i)
#define put(_x) cout<<_x<<endl
#define DEBUG cerr<<"-----------------\n"<<__LINE__<<endl<<"-----------------\n"
#define _1 first
#define _2 second
#define pii pair<int,int>
using namespace std;
int n,m; 
const int N=200005;
string s1[N],s2[N];
string t1[N],t2[N];
int ans[N];
bool ok[N];
const int mod=1000000009;
const int base=1331;
map<int,vector<pii> > mp;//哈希表 
int l[N];
int geth(string s){
	int ans=0;
	for(auto ch:s){
		ans=(ans*base%mod+ch-'0'+mod)%mod;
	}
	return ans;
}
#define it map<int,vector<int> >::iterator
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	up(i,1,n){
		string a,b;cin>>a>>b;
		int len=a.size(),l=0,r=len-1;
		for(;l<len&&a[l]==b[l];++l);
		for(;r&&a[r]==b[r];--r);
		s1[i]=a.substr(l,r-l+1);
		s2[i]=b.substr(l,r-l+1);
		int h1=geth(s1[i]),h2=geth(s2[i]);
		mp[h1].push_back({h2,len});
	}
	up(i,1,m){
		string a,b;cin>>a>>b;l[i]=b.size();
		if(a.size()!=b.size()){
			ans[i]=0;ok[i]=1;
			continue;
		}
		int len=a.size(),l=0,r=len-1;
		for(;l<len&&a[l]==b[l];++l);
		for(;r&&a[r]==b[r];--r);
		t1[i]=a.substr(l,r-l+1);
		t2[i]=b.substr(l,r-l+1);
	}
	up(i,1,m){
//		cout<<l[i]<<endl;
		if(ok[i]) continue;
		string a=t1[i],b=t2[i];
		int h1=geth(a),h2=geth(b);
//		cout<<h2<<endl;
		for(int j=0;j<mp[h1].size();j++){
			auto x=mp[h1][j];
			int h=x._1,len=x._2;
//			cout<<i<<' '<<h<<' '<<len<<endl;
			if(h==h2&&len<=l[i]){
//				cout<<i<<endl;
				
				ans[i]++;
			}
		}
	}
	up(i,1,m) cout<<ans[i]<<endl;
	return 0;
}
/*存样例
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

2
0

3 4
a b
b c
c d
aa bb
aa b
a c
b a

0
0
0
0

1 1
aba aaa
b a

4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex

*/
/*思路
字符串？冷门
可以哈希吧……话说总长1e7的字符串不会被卡常吗 
先把两个字符串“掐头去尾” 每个字符串都双模哈希一下 
代码又臭又长 但样例过了 
大样例1没过。。。 
*/
/*闲话
我是@__CrossBow_EXE__，上午我在SD-J00628.
关注我谢谢
//freopen
//feropen
IAKIOI
求上迷惑代码大赏
上午340pts应该有了，看下午怎么说
*/

