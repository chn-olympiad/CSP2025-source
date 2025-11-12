#include<bits/stdc++.h>
using namespace std;

int a[5010];
priority_queue<int> pq;

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++)cin >> a[i];
	
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[3]+a[2]>a[1]&&a[1]+a[3]>a[2]) cout << 1;
		else cout << 0;
		return 0;
	}
	
	int sum=0;
	int cnt = 0;
	
	for(int i=7; i<=pow(2, n); i++){
		int j = i;
		int o = 1;
		while(j){
			if(j&1){
				pq.push(a[o]);
				sum += a[o];
			} 
			o++; j >>= 1;
		}
		if(pq.size()>=3 && sum > 2 * pq.top()){
			cnt ++;
		}
		while(pq.size())pq.pop();
		sum = 0;
	}
	
	cout << cnt;
	
	return 0;
}
