#include <bits/stdc++.h>
using namespace std;
int maxx[10000001],a[1000001],b[1001],c[10000001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//伟大的CCF啊，就让我拿个二等吧 
	int t;
	cin >> t;
	for (int ff = 1;ff <= t;ff++){
		int n;
		cin >> n;
		int ifsa = 1,ifsb = 1;//特殊性质A、B 
		for (int i = 1;i <= n;i++){
			cin >> a[i];
			cin >> b[i];
			cin >> c[i];
			if (c[i] != 0){
				ifsb = 0;
				ifsa = 0;
			}
			if (b[i] != 0){
				ifsa = 0;
			}
			maxx[i] = max(a[i],max(b[i],c[i]));
		}
		int sum = 0;
//		cout << ifsa << ifsb;
		if (ifsa == 1){//特殊性质a 
			sort(a,a + n + 1);
			for (int i = n;n >= n / 2;i--){
				sum += a[i];
			}
			cout << sum;
		}
		else if (ifsb == 1 && ifsa ==0){//特殊性质b 
			sort(a,a + n + 1);
			sort(b,b + n + 1);
			for (int i = n;n >= n / 2;i--){
				sum += a[i];
			}
			for (int i = n;n >= n / 2;i--){
				sum += b[i];
			}
			cout << sum;
		}
		else if (n == 2){
			cout << max(b[1] + a[2],max(b[1] + a[3],max(b[2] + a[1],max(b[2] + a[3],max(b[3] + a[1],b[3] + a[2])))));
		}
		else{
			for (int i = 1;i <= n;i++){
				sum += maxx[i];
			}
			cout << sum;
		}
	}
	return 0;
}
