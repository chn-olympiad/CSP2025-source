#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[520520];
int b[521314];
int ans[500010];
int cnt=1;
void slove(int x){
	int e=k^b[x];
	for(int i=x-1;i>=0;i--){
		if(b[i]==e){
			if(x<ans[cnt-1]){
				ans[cnt++]=i+1;
			}
			else if(i+1<=ans[cnt-1]){
				ans[cnt-1]=i+1;
			}
			break;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ans[0]=1e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	for(int i=n;i>=1;i--){
		slove(i);
	}
	cout<<cnt-1;
	return 0;
}