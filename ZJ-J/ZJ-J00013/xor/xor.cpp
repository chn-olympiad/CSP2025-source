#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],t;
bool fl;
void dfs(int i,int x){
	if(i==0){
		fl=1;
		return;
	}
	for(int l=x+1;l<=n-(i-1)*n/t;l++){
		for(int r=l;r<=n-(i-1)*n/t;r++){
			int s=a[l];
			for(int j=l+1;j<=r;j++){
				s=s^a[j];
			}
			if(s!=k){
				continue;
			}
			dfs(i-1,r);
			if(fl==1){
				return;
			}
		}
	}
}
bool f(int x){
	t=x;
	fl=0;
	dfs(x,0);
	if(fl==1){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool A=1,B=1;
	int cnt1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt1++;
		if(A!=0&&a[i]!=1)A=0;
		if(B!=0&&a[i]!=1&&a[i]!=0)B=0;
	}
	if(A){
		cout<<n/2;
		return 0;
	}
	if(B&&k==1){
		cout<<cnt1;
		return 0;
	}
	if(B&&k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				cnt++;
				i++;
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int i=n-1;i>=1;i--){
		if(f(i)){
			cout<<i;
			return 0;
		}
	}
	cout<<0;
}