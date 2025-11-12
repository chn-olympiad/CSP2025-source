#include<bits/stdc++.h>
using namespace std;
long long mod=998244353,z[10005];
long long n,s[10005],ans,t[5005],m[100005],l[100005];
bool check(){
	long long v=0,cnt=0,mm=0,q=0,k=0;
	for(int i=1;i<=n;i++){
		if(t[i]){
			mm=max(mm,s[i]);
			q=q+i;
			v+=s[i];
			k+=mm;
			cnt++;	
		}
	}
	if(cnt<3||mm*2>=v||(l[mm]&&m[v]&&z[q])) return false;
	l[mm]++;
	m[v]++;
	z[q]++;
	return true;
}
void dfs(int x){
	if(x>n+1)
		return;
	if(check()){
		ans++;
	}
	t[x]=1;
	dfs(x+1);
	t[x]=0;
	dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	dfs(1);
	cout<<ans%mod;
	return 0; 
}
