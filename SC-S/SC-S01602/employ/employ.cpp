#include<bits/stdc++.h>
#define endl '\n'
#define ri register int
#define int long long
#define fixedset(a) fixed << setprecision(a)
#define pii pair<int,int>
#define mp make_pair
#define ls(x) x<<1
#define rs(x) x<<1|1
#define eps 1e-7
#define inf 2114514
#define mf 5011
#define sf 1011
#define MOD 998244353
#define mod(x) (x+MOD)%MOD;
using namespace std;
int n,m,ans,val[inf];
int mul[inf];
string num;
bool book[sf]; int rcd[sf];
void pre(){
	mul[0]=1;
	for(ri i=1;i<inf;i++) mul[i]=mod(mul[i-1]*i);
	return ;
}
void dfs(int pos,int bnd){ //当前是第几个,上限
	if(pos==bnd){
		int cur=0,cnt=0;
		for(ri i=1;i<=n;i++){
			if(num[i]=='0') cur++;
			else if(num[i]=='1'){
				if(val[rcd[i]]>cur){
					cur=0,cnt=cnt+1;
				}else cur++;
			}
		}
		if(cnt>=m) ans++;
		return ;
	}
	
	for(ri i=1;i<=n;i++){
		if(book[i]) continue;
		book[i]=true; rcd[pos]=i;
		dfs(pos+1,bnd);
		book[i]=false;
	}
	return ;
}
bool checkans1(){
	if(m==n) return true;
	return false;
}
bool checkans2(){
	for(ri i=1;i<=n;i++) if(num[i]=='0') return false;
	return true;
}
void getans1(){
	bool flag=true;
	for(ri i=1;i<=n;i++) if(num[i]!='1') flag=false; 
	if(!flag) ans=0;
	else ans=mul[n];
	return ;
}
void getans2(){
	ans=mul[n];
	return ;
}
void getans3(){
	dfs(1,n+1);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> num; num=' '+num;
	for(ri i=1;i<=n;i++) cin >> val[i];
	pre();
	
	if(checkans1()) getans1();
	else if(checkans2()) getans2();
	else getans3();
	
	cout << ans%MOD << endl;
	return 0;
}