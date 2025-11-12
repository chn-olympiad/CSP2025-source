#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define fir first
#define sec second
#define file(_1) freopen(_1".in","r",stdin),freopen(_1".out","w",stdout);
#define error(_) cerr<<_<<endl
#define look_memory cerr<<(&m2-&m1)/1024.00/1024.0<<"MB"<<endl;
#define look_time cerr<<(t2-t1)/1000.0<<"s"<<endl;
using namespace std;
auto t1=clock();
bool m1;
template <typename T>
inline void read(T &x){
	T f=1,c=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		c=(c<<3)+(c<<1)+(ch^48);
		ch=getchar();
	}
	x=f*c;
}

template<typename T,typename ...Args>
inline void read(T &x,Args &...args){
	read(x),read(args...);
}
namespace white_carton{
	int n,q,l[200100],r[200100];
	string s[200100][2],q1,q2;
	map<pair<string,string>,vector<int>> mp;
	void solve(){
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>s[i][0]>>s[i][1];
			r[i]=s[i][0].size()-1;
			while(l[i]<=r[i]&&s[i][0][l[i]]==s[i][1][l[i]]){
				l[i]++;
			}
			while(r[i]>=0&&s[i][0][r[i]]==s[i][1][r[i]]){
				r[i]--;
			}
			if(l[i]>r[i]){
				continue;
			}
			string s1,s2;
			for(int j=l[i];j<=r[i];j++){
				s1+=s[i][0][j];
				s2+=s[i][1][j];
			}
			mp[{s1,s2}].pb(i);
		}
		for(int i=1;i<=q;i++){
			int ans=0;
			cin>>q1>>q2;
			if(q1.size()!=q2.size()){
				cout<<0<<endl;
				continue;
			}
			int l1=0,r1=q1.size()-1;
			while(l1<=r1&&q1[l1]==q2[l1]){
				l1++;
			}
			while(r1>=0&&q1[r1]==q2[r1]){
				r1--;
			}
			string s1,s2;
			for(int i=l1;i<=r1;i++){
				s1+=q1[i],s2+=q2[i];
			}
			for(auto i:mp[{s1,s2}]){
				if(l[i]>l1){
					continue;
				}
				if(s[i][0].size()-r[i]>q1.size()-r1){
					continue;
				}
				int L=l1-l[i],R=L+s[i][0].size()-1,flag=0;
				for(int j=L;j<=R;j++){
					if(s[i][0][j-L]!=q1[j]||s[i][1][j-L]!=q2[j]){
						flag=1;
						break;
					}
				}
				if(!flag){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
}
int T=1;
bool m2;
signed main(){
	file("replace");
//	T=read();
	while(T--){
		white_carton::solve();
	}
	auto t2=clock();
	look_time;
	look_memory;
}
//1.快读
//2.注意空间
//3.多测清数据
//4.对拍
//5.打满暴力
//6.文件
//7. RP++;



//starback24

