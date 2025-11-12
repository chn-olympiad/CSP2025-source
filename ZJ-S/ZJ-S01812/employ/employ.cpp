#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m;
string c;
int num;
int z[505],p[505],s[505];
bool visit;
unsigned long long ans;
bool pd(){
	int k=0;
	for(register int i=1;i<=n;i++)
		if(s[i]>z[i]&&c[i-1]=='1')k++;
	if(k>=m)return true;
	else return false;
}
bool dfs(int j,int n){
	if(j==n+1){
		if(pd()==true)ans++;
		ans%=N;
	}
	for(register int i=1;i<=n;i++)
		if(s[i]==0){
			s[i]=p[j];
			dfs(j+1,n);
			s[i]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>c;
	for(register int i=1;i<=n;i++){
		if(c[i-1]=='0'){
			z[i]=z[i-1]+1;
			visit=1;
		}
		else z[i]=z[i-1];
	}
	for(register int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+n+1);
	for(register int i=1;i<=n;i++){
		if(z[i]<p[i])num++;
	}
	if(num<m){
		cout<<0;
		return 0;
	}
	if(visit==0||num==n){
		ans=1;
		for(register int i=1;i<=n;i++){
			ans*=i;
			ans%=N;
		}
		cout<<ans;
		return 0;
	}//A
	dfs(1,n);
	cout<<ans%N;
	return 0;
}
