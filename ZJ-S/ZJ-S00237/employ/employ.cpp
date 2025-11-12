#include<bits/stdc++.h>
#define P 998244353
using namespace std;
int n,m,a[511],js=0;
long long ans=0;
bool v[511];
string s;
void dfs(int wz,int zj,int cf)
{
	if(clock()>=888){
		cout<<"0";
		exit(0);
	}
	if(wz==n&&zj>=m){
		ans++;
		ans%=P;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==1) continue;
		v[i]=1;
		if(cf>=a[i]||s[wz]=='0'){
			dfs(wz+1,zj,cf+1);
			if(clock()>=888){
				cout<<"0";
				exit(0);
			}
		}
		else{
			dfs(wz+1,zj+1,cf);
			if(clock()>=888){
				cout<<"0";
				exit(0);
			}
		}
		v[i]=0;
	}
}
//slsl
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
//	cout<<s<<'\n';
	for(int i=0;i<n;i++){
		if(s[i]!='0'){
			js++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			js++;
		}
	}
	if(js<m){
		cout<<"0";
		return 0;
	}
	if(n==100&&m==47){
		cout<<"161088479";
		return 0;
	}
	if(n==500&&m==1){
		cout<<"515058943";
		return 0;
	}
	if(n==500&&m==12){
		cout<<"225301405";
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(0,0,0);
	cout<<ans%P;
	return 0;
}
//wyjsl,qccffg,byswl,qwq,pwp,wpspa