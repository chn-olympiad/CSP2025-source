#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int k,n,a[N],b[N],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			continue;
		} 
		for(int j=i+1;j<=n;j++){
			int sum=0;
			for(int s=i;s<=j;s++) sum^=a[s];
			if(sum==k) ans++,i=j+1;
		}
	}
	cout<<ans;
}
