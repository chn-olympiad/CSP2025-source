#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int len=1;len<=n;len++){
		for(int i=1;len+i-1<=n;i++){
			int j=i+len-1,x=0;
			for(int k=i;k<=j;k++){
				x^=a[k];
			}
			if(x==k){
				if(i==j)ans=1;
				else ans=j-i;
			}
		}
	}
	cout<<ans;
}
