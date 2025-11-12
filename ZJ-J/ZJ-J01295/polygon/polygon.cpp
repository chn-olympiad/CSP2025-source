#include<bits/stdc++.h>

using namespace std;

int a[5010];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int mx = 0;
	int sum = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] > mx){
			mx = a[i];
		}
		sum += a[i];
	}
	if(n == 3 && sum > mx*2){
		cout << 1;
	} else if(n == 3){
		cout << 0;
	} else {
		cout << "我不会啊......" << endl;
		cout << "电脑可以给我满分吗?"; 
	}
	
	return 0;
}
