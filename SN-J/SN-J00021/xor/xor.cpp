#include<bits/stdc++.h>
using namespace std;
int n,k,now,ans;
int a[500010],qjh[500010][40];
int mb[50];
map<int,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int q=k,qq=0;
	while(q){
		if(q%2==1){
			mb[qq]=1;
		}
		q/=2;
		qq++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i],tt=0;
		for(int j=0;j<=30;j++){
			qjh[i][j]=qjh[i-1][j];
		}
		while(t){
			if(t%2==1){
				qjh[i][tt]++;
			}
			t/=2;
			tt++;
		}
	}
	for(int i=1;i<=n;i++){
		int xq=0;
		for(int j=0;j<=30;j++){
			if(qjh[i][j]%2!=mb[j]){
				xq+=(1<<j);
			}
		}
		if((mp[xq]>now)||(mp[xq]==now&&now!=0)||(mp[xq]==now&&xq==0)){
			now=i;
			ans++;
		}
		int w=0;
		for(int j=0;j<=30;j++){
			if(qjh[i][j]%2==1){
				w+=(1<<j);
			}
		}
		mp[w]=i;
	}
	cout<<ans;
	return 0;
}
