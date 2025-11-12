#include <bits/stdc++.h>
using namespace std;
int a[1000001],b[1000001],c[10000001],num[1000000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//DV炸了 
	int n,m,k;
	cin >> n >> m>> k;
	int sum = 0;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			if (a[i] < a[j]){
				swap(a[i],a[j]);
				swap(b[i],b[j]);
				swap(c[i],c[j]);
			}
		}
	}
	//DV修好了（证明了CCF的伟大） 
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= i;j++){
			num[j]=1;
		}
		int sum = 0;
		int ii = 1;
		for (int j = 1;j <= i;j++){
			sum += num[j];
			if (num[j] == 0){
				ii = 0;
				break;
			}
		}
		if (ii = 0)continue;
		else{
			cout << sum;
			break;
		}
	}
	cout << sum;
	return 0;
} 
