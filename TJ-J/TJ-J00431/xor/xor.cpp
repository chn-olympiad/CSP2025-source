#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt;
int n,k,qt,mxx;
void dfs(int tp,int cnt){
	if(tp>n){
		mxx=max(mxx,cnt);
		return;
	}
	for(int i=tp;i<=n;i++){
		qt^=a[i];
		if(qt==k){
			qt=0;
			tp=i;
			cnt++;
			break;
		}
	}
	qt=0;
	dfs(tp+1,cnt);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<mxx;
	return 0;
}
