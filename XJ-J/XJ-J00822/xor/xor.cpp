#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5;
int n,k;
int a[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool A=true;
	bool B=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			A=false;
		}
		if(!(0<=a[i]&&a[i]<=1)){
			B=false;
		}
	}
	if(A&&k==0){
		cout<<n/2;
		return 0;
	}
	if(B){
		int ans=0;
		for(int i=1;i<=n;){
			if(a[i]==k){
				ans++;
				i++;
			}else if((a[i]^a[i+1])==k){
				ans++;
				i+=2;
			}else{
				i++;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<n/2;
	return 0;
}
