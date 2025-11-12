/*
记住，freopen前不可以读入！


*/
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define ls (id<<1)
#define rs (id<<1|1)
inline int read(){
	int sum=0,k=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){sum=sum*10+c-48;c=getchar();}
	return sum*k;
}
using namespace std;
const int M=1e6+110;

bool ok;
int n,m,a[505],kans;
string s;

inline void dfs(int st,vector<int>qwq){
	if(qwq.size()==n){
		int fail=0,pl=0,success=0;
		for(auto x:qwq){
			if(success>=m) return kans++,void();
			if(s[pl]=='0'){pl++;fail++;continue;}
			if(a[x]<=fail){pl++;fail++;continue;}
			pl++;
			success++;
		}
		if(success>=m) return kans++,void();
		return void ();
	}
	bitset<11>p,q;vector<int>f;
	p=st;
	for(int i=1;i<=n;i++){
		if(p.test(i-1)==0){
			q=p;q.set(i-1);
			f=qwq;f.push_back(i);
			dfs(q.to_ulong(),f);
		}
	}
}





signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	for(int i=1;i<=n;i++){ 
		a[i]=read();
		if(a[i]!=1) ok=1;
	}
	//性质A好像挺好写的，试试吧qwq
	if(ok==0){
		int pl=0;
		while(pl<(int)s.size()&&s[pl]=='1'){
			pl++;
		}//如果前面的有一个不录用，后面的全跑了，所以可以做
		if(pl<m-1) return cout<<0<<'\n'&&0;
		int ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
		return cout<<ans<<'\n'&&0;
	}
	if(m==n){
		for(int i=1;i<=n;i++) if(a[i]==0) return cout<<0<<'\n'&&0;
		for(int i=0;i<(int)s.size();i++) if(s[i]!=1) return cout<<0<<'\n'&&0;
		int ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
		return cout<<ans<<'\n'&&0;
	}
	if(m==1){
		int naixin=0,cnt;//取一个人至少要的耐心
		for(int i=0;i<(int)s.size();i++) if(s[i]=='1'){naixin=i;break;}
		if(naixin==0) return cout<<0<<'\n'&&0;
		for(int i=1;i<=n;i++){
			if(a[i]>=naixin) cnt++;
		}
		int ans=1;
		for(int i=1;i<=n-1;i++) ans=(ans*i)%998244353;
		ans=(ans*cnt)%998244353;
		return cout<<ans<<'\n'&&0;
	}
	if(n<=10){
		vector<int>ooo;
		dfs(0,ooo);
		cout<<kans<<'\n';
		return 0;
	}else cout<<0<<'\n';
	return 0;
}
/*
神秘T4 考虑骗分）嘻嘻嘻
*/
/*
3 2
101
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/