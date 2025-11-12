#include <bits/stdc++.h>
using namespace std;
int MOD = 998244353;
int n,a[5050],b[5050];
long long jc[5050],ans;
//有一种情况没考虑（悲 
//能不能骗到分
//求 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	jc[1] = 1;
	for(int i = 2;i<=n;i++){
		jc[i] = jc[i-1] * i % MOD;
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		b[i] = a[i]+ b[i-1];
	}
	for(int i = 3;i<=n;i++){//边数 
		//cout<<"边数:"<<i<<endl; 
		for(int j = i;j<=n;j++){//最大值 
			//cout<<"最大值:"<<a[j]<<endl; 
			int cnt = 0;
			for(int k = 1;k<=j-i+1;k++){//最小值 
				if(a[k] != a[k-1]) cnt = 0;
				cnt++;
				if(b[k+i-2]-b[k-1] > a[j]){
					//cout<<"当最小值为"<<a[k]<<"时，满足条件"<<endl;
					if(j-k+1 == i){
						ans= (ans + jc[cnt]) % MOD;
						//cout<<"ans+"<<jc[cnt]<<endl;
						cnt = 0;
						break;
					}
					ans += jc[j-k+1] / jc[i] / jc[j-k+1-i] % MOD;
					//cout<<"ans+"<<jc[j-k+1] / jc[i] / jc[j-k+1-i]<<endl;
					cnt = 0;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
