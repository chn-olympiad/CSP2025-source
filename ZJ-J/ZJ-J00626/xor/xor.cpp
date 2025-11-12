#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[505050];
int xors[505050];
int ans;
int maxor[505050];
int www(int st){
	if(st>n)return 0;
	int cnt=0;
	for(int i=st;i<=n;i++){
		if((xors[i]^xors[st-1])==k){
//			cout<<st<<" "<<i<<" "<<(xors[i]^xors[st-1]);
//			puts("");
			if(maxor[i+1]<0){
				cnt=max(cnt,www(i+1)+1);
				maxor[i+1]=www(i+1);
			}
			else{
//				if(cnt>maxor[i+1])maxor[i+1]=max(maxor[i+1],www(i+1));
				cnt=max(cnt,maxor[i+1]+1);
			}
		}
	}
	return cnt;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xors[i]=xors[i-1]^a[i];
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			int ans=xors[j]^xors[i-1];
//			if(i>j)cout<<"  ";
//			else cout<<ans<<" ";
//		}
//		puts("");
//	}
	for(int i=1;i<=n;i++){
		memset(maxor,-1,sizeof(maxor));
		ans=max(ans,www(i));
	}
	cout<<ans;
	return 0;
}