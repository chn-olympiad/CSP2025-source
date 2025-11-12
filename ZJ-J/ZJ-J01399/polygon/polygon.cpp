#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans;
void fun(int x,int num,int maxx,int sum){
	if(x>n) {
		if(sum>=3&&num>2*maxx) {
			ans++;
			ans%=mod;
		}
		return;
	}
	fun(x+1,num+a[x],max(maxx,a[x]),sum+1);
	fun(x+1,num,maxx,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	fun(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
