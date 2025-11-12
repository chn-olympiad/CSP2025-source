#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005],b[1005]={0},ans=0;
void sou(int now,int quan,int s){
	quan=(quan xor a[now]),b[now]=1;
	if(quan==k){
		ans++;
		return;
	}
	else if(now==n){
		for(int i=s;i<=now;i++) b[i]=0;
		return;
	}
	else{
		if(b[now+1]!=1) sou(now+1,quan,s);
		else{
			for(int i=s;i<=now;i++) b[i]=0;
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			b[i]=1;
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=1) sou(i,0,i);
	}
	cout<<ans;
	return 0;
}
