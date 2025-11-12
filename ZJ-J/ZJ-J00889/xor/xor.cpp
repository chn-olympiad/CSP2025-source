#include<bits/stdc++.h>
using namespace std;
int a[500010];
int h(int x,int y){
	return x^y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum=h(sum,h(a[i],a[j]));
			if(sum==k) {
				ans++;
				break;
			}
			if(sum>k){
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}

	
