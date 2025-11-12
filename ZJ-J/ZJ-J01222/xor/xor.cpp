#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10001];
int cnt = 0;
void dfs(int x,int t){
	if(x==k){
		cnt++;
		//cout<<x<<" "<<t<<endl;
		x=a[t+1];		
	}
	if(t==n){
		return;
	}
	if(x==a[t+1]){
		dfs(x,t+1);	
	}else{
		dfs(x^a[t+1],t+1);
		dfs(a[t+1],t+1);
	}

}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2){
		int yj = 0;
		int yu = a[1]^a[2];
		if(a[1]==0){
			yj++;
		}
		if(a[2]==0){
			yj++;
		}
		if(yu==0){
			cout<<max(1,yj);
		}else{
			cout<<0<<endl;
		}
		return 0;
	}
	if(k==0){	
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			cnt++;
		}		
	}
	cout<<cnt<<endl;
	return 0;
	}
	dfs(a[1],1);
	cout<<cnt<<endl;
	return 0;
}