#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int l=1,ans=0;
int a[N],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=i;j>=l;j--){
			x^=a[j];
			if(x==k){
				ans++;
				l=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

