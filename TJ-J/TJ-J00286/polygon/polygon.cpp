#include<bits/stdc++.h>
using namespace std;
int a[5002];
struct al{
	int a1;
	vector<int> im;
};
al dp[5002];
/*int sc(int k,int p,int d,int e){
	d += 1; 
	if(p == 0){
		return a[p];
	}
	else{
		for(int i = p;i >= 0;i++){
			
		}
 	}
}*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int m = 0,l = 0;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		dp[i].a1 = a[i];	
		l += a[i];
		m = max(m,a[i]);
	}
	sort(a,a + n);
	for(int i = 0;i < n;i++){
		dp[i].a1 = a[i];	
	}
	m *= 2;
	if(n == 3){
		if(l > m){
			cout << 1;
			return 0;
		}
		else{
			cout << 0;
			return 0;
		}	
	} 
	int ans = 0;
	for(int i = 0;i < n;i++){
		int ls = dp[i].a1;
		dp[i].im.push_back(ls);
		for(int j = 0;j < i;j++){
			for(int &t : dp[j].im){
				dp[i].im.push_back(ls + t);
				if((ls + t) > (ls * 2)){
					ans += 1;
					ans = ans % 988;
					ans = ans % 244;
					ans = ans % 353;
				}
			}
		}
	}
	cout << ans;
	return 0;	
}
