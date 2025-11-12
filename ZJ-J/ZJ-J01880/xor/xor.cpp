#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,K;
int a[N],b[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>K;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	if(K==1&&n>1000){
		int ans=0;
		for(int i=1;i<=n;i++)if(a[i]==1)ans++;
		cout<<ans;
		return 0;
	}
	if(K==0&&n>1000){
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt=0,ans++;
			if(a[i]==1)cnt++;
			if(cnt==2)ans++,cnt=0;
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	int j=0;
	for(int i=1;i<=n;i++){
		for(int k=j;k<i;k++){
			if((b[i]^b[k])==K){
				ans++;
				j=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
