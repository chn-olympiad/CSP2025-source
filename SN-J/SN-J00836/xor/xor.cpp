#include<bits/stdc++.h>
using namespace std;
int n,k,pre[500005],arr[500005],cnt,ans;
void search(int nowid){
	if(nowid==n+1){
	    cnt=max(ans,cnt);
	    return;
	}
	for(int i=1;i<=n;i++){
		if((pre[i]^pre[nowid-1])==k){
			ans++;
			search(i+1);
			ans--;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>arr[i];
    	pre[i]=pre[i-1]^arr[i];
	}
	search(1);
	cout<<cnt;
	return 0;
}
