#include <bits/stdc++.h>
using namespace std;
long long fir[10000];
long long sec[10000];
long long thi[10000];
long long ma[10000],mb[10000],mc[10000];
long long n,maxn;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	long long ans = 0;
	while(t--){
		cin >> n;
		maxn = n/2;
		
		for(int i=1;i<=n;i++){
			cin >> fir[i] >> sec[i] >> thi[i];
			ma[i] = fir[i];
			mb[i] = sec[i];
			mc[i] = thi[i];
		}
		sort(ma+1,ma+n);
		sort(mb+1,mb+n);
		sort(mc+1,mc+n);
		if(mb[n] == 0 && mc[n] == 0){
			for(int i=n;i>=n/2;i--){
				ans += ma[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
