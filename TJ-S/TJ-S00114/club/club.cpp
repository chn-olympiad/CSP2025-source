#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int a[200005][3];
priority_queue<int> pq0, pq1, pq2, e;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a0,a1,a2,ans;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n;
		a0 = 0;
		a1 = 0;
		a2 = 0;
		ans = 0;
		pq0 = e;
		pq1 = e;
		pq2 = e;
		for(int j=1;j<=n;j++){
			scanf("%d%d%d", &a[j][0], &a[j][1], &a[j][2], stdin);
			if(a[j][0] > a[j][1] && a[j][0] > a[j][2]){
				ans += a[j][0];
				a0++;
				pq0.push(max(a[j][1], a[j][2]) - a[j][0]);
			}
			else if(a[j][1] > a[j][2]){
				ans += a[j][1];
				a1++;
				pq1.push(max(a[j][0], a[j][2]) - a[j][1]);
			}
			else{
				ans += a[j][2];
				a2++;
				pq2.push(max(a[j][0], a[j][1]) - a[j][2]);
			}
			
		}
		if(a0 > n/2){
			for(int k=a0;k>n/2;k--){
				ans += pq0.top();
				pq0.pop();
			}
		}
		else if(a1 > n/2){
			for(int k=a1;k>n/2;k--){
				ans += pq1.top();
				pq1.pop();
			}
		}
		else if(a2 > n/2){
			for(int k=a2;k>n/2;k--){
				ans += pq2.top();
				pq2.pop();
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
