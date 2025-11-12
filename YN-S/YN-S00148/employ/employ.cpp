#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=600;
long long n,m,nx[MAXN],ans;
bool people[MAXN];
string s;
void dfs(long long no,long long lren,long long sn);
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	cin>>s;
	for (int i=0;i<n;i++){
		scanf("%lld",&nx[i]);
	}
	dfs(0,0,0);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void dfs(long long no,long long lren,long long sn){
	if (no==n){
		if (n-lren<=m) ans++;
		return ;
	}
	for (int i=(int)sn;i<n;i++){
		if (!people[i]){
			people[i]=1;
			if (nx[i]<=lren||s[i]=='1'){
				dfs(no+1,lren+1,0);
			}else{
				dfs(no+1,lren,0);
			}
			people[i]=0;
		}
		dfs(no,lren,i+1);
	}
	return ;
}
