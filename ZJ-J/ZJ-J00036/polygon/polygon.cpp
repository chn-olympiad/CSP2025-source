#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int s[5005];
void f(int now,int sum,int mx){
	if(now>n){
		if(sum>mx+mx){
			ans++;
			ans%=998244353;
		}
		return;
	}
	f(now+1,sum,mx);
	f(now+1,sum+s[now],max(mx,s[now]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n);
	f(1,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
