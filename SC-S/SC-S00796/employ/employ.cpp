#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int n,m,cnt=0,ans=0;
int c[505];
bool fa=1,fb=1;
struct Tester{
	int id,order;
}f[505];
bool cmp(Tester a,Tester b){
	return a.order<b.order;
}
void getans(){
	int getout=0,pass=0;
	Tester a[505];
	for(int i=1;i<=n;i++){//备份
//		cout<<f[i].order<<' ';
		a[i].order=f[i].order;
		a[i].id=f[i].id;
	}
//	cout<<endl;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){
//			cout<<"Too hard\n";
			getout++;
			continue;
		}
		if(c[a[i].id]<=getout){
//			cout<<"Too getout\n";
			getout++;
			continue;
		}
		pass++;
//		cout<<"Pass\n";
	}
	if(pass>=m)ans++;
}
void dfs(int x){
	if(x>n){
		getans();
		ans%=998244353;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i].order==0){
			f[i].order=x;
			dfs(x+1);
			f[i].order=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		f[i].id=i;
		cin>>c[i];
		if(c[i]!=0)cnt++;
	}
	dfs(1);
	cout<<ans;
	return 0;
}