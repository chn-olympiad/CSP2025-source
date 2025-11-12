#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,a[N],r,sum;
int x[N],y[N],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum=sum^a[j];
			if(sum==k){
				++cnt;
				x[cnt]=i;
				y[cnt]=j;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(x[i]>r){
			r=y[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
