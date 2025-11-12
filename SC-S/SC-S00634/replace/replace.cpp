#include<iostream>
#include<cstring>
#include<map>
using namespace std;
const int maxn = 2e5+5;
const int maxlen = 5e6+5;
string s,q;
int n,ques;
map<string,string> mp;

inline bool check(int l,int r,int LEN){
	for(int i=0;i<l;i++) if(s[i]!=q[i]) return false;
	for(int i=r+1;i<LEN;i++) if(s[i]!=q[i]) return false;
	return true;
}

inline void work(){
	int lens=s.length(),lenq=q.length();
	if(lens!=lenq){
		cout<<0<<'\n';
		return;
	}
	long long ans=0;
	for(int i=0;i<lens;i++){
		string ss,sq;
		for(int j=i;j<lens;j++){
			ss=ss+s[j];
			sq=sq+q[j];
			if(mp[ss]==sq && check(i,j,lens)) ans++;
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>ques;
	for(int i=1;i<=n;i++){
		cin>>s>>q;
		mp[s]=q;
	}
	for(int i=1;i<=ques;i++){
		cin>>s>>q;
		work();
	}
	return 0;
}
/*
17:48 啊？AC自动机 
17:52 AC自动机忘完了，不写了
18:12 敲出第一份暴力，没过样例 
18:19 暴力过样例了，评测姬我求你了多给点分吧 
*/