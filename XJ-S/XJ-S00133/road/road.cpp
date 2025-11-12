#include <bits/stdc++.h>
using namespace std;
int n[100010];//城市
int m[100010];//连接的道路
int j[100010];//乡镇
int w[100010];//钱数 
int diff[100010];
int k,a;//k为改造城市的数量 ,a为钱数
int sum1=0,sum2=0;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>k>>a;
	for(int i=1; i<=a; i++) {
		cin>>n[i];
	}
	//输入城市
	for(int i=1; i<=a; i++) {
		cin>>m[i];
	}
	//输入道路
	for(int i=1;i<=a;i++){
		cin>>w[i];
	}
	for(int i=1; i<=a; i++) {
		w[i]=w[i]*m[i];
		diff[i]=w[i]*m[i];
	}	
	for(int i=1; i<=a; i++) {
		if(diff[i]>0) {
			sum1=sum1+diff[i];
		} else if(diff[i]<0) {
			sum2=sum2+(-diff[i]);
		}
	}
	cout<<min(sum1,sum2);

	fclose(stdin);
	fclose(stdout);
	return 0;
}




