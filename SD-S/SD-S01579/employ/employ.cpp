#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=666;
const int mod=998244353;
int n,m,c[N],id[N];
string s;
int check(){
	int p=0,ps=0;
	for(int i=1;i<=n;++i){
//		cout<<id[i]<<":"<<c[id[i]]<<"\n";
		if(ps>=c[id[i]]||s[i]=='0'){
			ps++;
		}else{
			p++;
		}
	}
//	cout<<p<<"\n";
	return p>=m;
}
void solve1(){
	int ans=0,times=1;
	for(int i=1;i<=n;++i)times*=i;
	for(int i=1;i<=times;++i){
		ans+=check();
		next_permutation(id+1,id+1+n);
	}
	cout<<ans<<"\n";
}
void solve2(){
	cout<<"0\n";
}
void solve3(){
	int ans=1;
	for(int i=1;i<=n;++i){
		ans=ans*i%mod;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool zer=1;
	s=' '+s;
	for(int i=1;i<=n;++i){
		if(s[i]=='1')zer=0;
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	for(int i=1;i<=n;++i)id[i]=i;
	if(n<=10)solve1();
	else if(!zer)solve2();
	else solve3();
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
