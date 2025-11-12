#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long t,n,a1[N],a2[N],a3[N],ans,s[N],na1,na2,na3;
void dfs(long long x,long long sum){
	if(x == n+1){
		ans = max(sum,ans);
		return;
	}
	if((ans-sum)>s[x-1])	return;
	if(na1+1<=n/2){
		na1++;
		dfs(x+1,sum+a1[x]);
		na1--;
	}
	if(na2+1<=n/2){
		na2++;
		dfs(x+1,sum+a2[x]);
		na2--;
	}
	if(na3+1<=n/2){
		na3++;
		dfs(x+1,sum+a3[x]);	
		na3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		for(long long i = 1;i<=n;i++)	cin >> a1[i] >> a2[i] >> a3[i];
		for(long long i = 1;i<=n;i++)	s[n-i] = s[n-i+1]+max(max(a1[n-i+1],a2[n-i+1]),a3[n-i+1]);
		dfs(1,0);
		cout << ans << endl;
	}  
	return 0;
	fclose(stdin);
	fclose(stdout);
} 