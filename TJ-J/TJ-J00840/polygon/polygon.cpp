#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int n,a[5005];
int b[5005];
long long cnt;
void f(int start,int now,int end){
	if(now>end){
		int len=0;
		for(int i=1;i<now;i++){
			len+=a[b[i]];
		}
		bool flag=1;
		for(int i=1;i<now;i++){
			if(len<=a[b[i]]*2){
				flag=0;
				break;
			}
		}
		if(flag==1){
			cnt++;
			cnt%=mod;
		}
		return;
	}
	for(int i=start;i<=n;i++){
		b[now]=i;
		f(i+1,now+1,end);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		f(1,1,i);
	}
	cout<<cnt%mod;
	return 0;
}
