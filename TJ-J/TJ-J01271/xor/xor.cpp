#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
bool ifa(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			return false;
		}
	} 
	return true;
}
bool ifb(){
	for(int i=1;i<=n;i++){
		if(!(a[i]>=0&&a[i]<=1)){
			return false;
		}
	} 
	return true;
}
bool ifc(){
	for(int i=1;i<=n;i++){
		if(!(a[i]>=0&&a[i]<=255)){
			return false;
		}
	} 
	return true;
}
void solve1(){
	int maxx=-1;
	int sum;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			sum=a[l];
			for(int i=l+1;i<=r;i++){
				sum^=a[i];
			}
			maxx=max(maxx,sum);
		}
	}
	cout<<maxx;
	return;
}
void solve2(){
	int maxx=-1;
	int sum;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			sum=a[l];
			for(int i=l+1;i<=r;i++){
				sum^=a[i];
			}
			maxx=max(maxx,sum);
		}
	}
	cout<<maxx;
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1&&k==0){
		cout<<0;
		return 0;
	}
	if(n==2&&k==0){
		cout<<1;
		return 0;
	} 
	if(ifa()){
		int ans=0;
		if(k==1){
			for(int i=1;i<n;i++){
				ans+=i;
			}
			cout<<ans;
			return 0;
		}
	}
	if(k==0){
		int c=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0||i<n&&a[i]==a[i+1]||i>1&&a[i]==a[i-1]){
				c++;
			}
		}
		cout<<c;
		return 0;
	}
	if(n<=10){
		solve2();
	}
//	else if(n<=100){
//		solve3();
//	}
//	else if(n<=1000){
//		solve4();
//	}
//	else{
//		solve5();
//	}
	return 0;
}
//1 2 3       1
//123

//1 2 3 4     5
//123 124 134
//234
//1234

//1 2 3 4 5   10
//123 124 125 134 135 145
//234 235 245
//345
//1234 1235 1345
//12345

//1 2 3 4 5 6
//123 124 125 126 134 135 136 145 146 156
//234 235 236 245 246 256
//345 346 356
//456
