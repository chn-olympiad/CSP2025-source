#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
bool vis[500005];
/*void change(int x,int y){
	for(int i=x;i<=y;i++)vis[i]=1;
}
bool check(int x,int y){
	for(int i=x;i<=y;i++)if(vis[i])return 0;
	return 1;
}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]==k)cout<<1;
		else cout<<0;return 0;
	}
	else if(n==2){
		int cnt=0;
		//cout<<(a[0]^a[1]);
		if((a[1]^a[2])==k)cnt++;
		if(a[1]==k)cnt++;
		if(a[2]==k)cnt++;
		cout<<cnt;return 0;
	}
	int cnt;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
				if(a[i]==k){
					ans++;
					//cout<<i<<','<<j<<endl;
				}
				continue;
			}
			else{
				cnt=a[i];
			}
			for(int k=i;k<=j;k++)
				if(k!=i)cnt^=a[k];
			if(cnt==k){
				ans++;
				//cout<<i<<','<<j<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
