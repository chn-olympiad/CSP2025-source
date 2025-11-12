#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=998244353ll;
ll n,m,ans=0ll;
ll c[510]/*,q[510]*/;
char s[510];
bool b[510];
void dfs(ll sum,ll cnt){
	if(cnt>n-m){
		return;
	}
	if(sum==n){
		ans++;
		ans%=p;
		//for(int i=1;i<=sum;i++){
		//	cout<<q[i]<<" ";
		//}
		//cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			sum++;
			//q[sum]=i;
			if(cnt>=c[i]||s[sum]=='0'){
				cnt++;
			}
			dfs(sum,cnt);
			if(cnt>=c[i]||s[sum]=='0'){
				cnt--;
			}
			sum--;
			b[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	bool flag=0;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		//if(c[i]==0ll){
		//	flag=1;
		//	break;
		//}
	}
	//if(flag){
	//	cout<<0;
	//	return 0;
	//}
	dfs(0ll,0ll);
	cout<<ans;
	return 0;
}
