#include<bits/stdc++.h>
using namespace std;

int n,a[5005],z;
struct sss{
	int sum_a,sum_b;
} sum[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i].sum_a=sum[i-1].sum_a+a[i];
		sum[i].sum_b=max(sum[i-1].sum_b,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(sum[i].sum_a-sum[j].sum_a>sum[i].sum_b*2) z++;
		}
	}
	/*for(int i=0;i<n;i++){
		int z=0;
		for(int j=0;j<n;j++){
			if(i!=j){
				z+=a[j];
			}
		}
		if(z>ma_x) ans++;
	}*/
	cout<<z;
	return 0;
}