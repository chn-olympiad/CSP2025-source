#include <iostream>
#include <algorithm>
using namespace std;
const long long MAXM=998244353;
long long m,a[5001],ans;
void dfs(int dq,int num,int maxn,int tot){
	if(dq==m){
		if(tot>2*maxn&&num>=3){
			ans++;ans%=MAXM;
		}return;
	}
	dfs(dq+1,num+1,a[dq+1],tot+a[dq+1]);
	dfs(dq+1,num,maxn,tot);
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}sort(a+1,a+m+1);
	for(int i=1;i<=m-2;i++){
		dfs(i,1,a[i],a[i]);
	}cout<<ans%MAXM<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}