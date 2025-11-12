#include <bits/stdc++.h>
using namespace std;
int n,m,a[200],aa[200],b[15][15],c = 1,r,xjb;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	xjb = n * m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	r = a[1];
	sort(a + 1,a + 1 + n * m);//坏事儿了，忘了sort的降序排列怎么写了，只能用蠢办法了，能对就行 
	for(int i = 1;i <= n * m;i++){
		aa[xjb] = a[i];
		xjb--;
	}
	for(int i = 1;i <= m;i++){
		if(i % 2 == 1){
			for(int j = 1;j <= n;j++){
				b[j][i] = aa[c];
				if(r == aa[c]){
					cout << i << ' ' << j;
					return 0;
				}
				c++;
			}
		}
		else{
			for(int j = n;j > 0;j--){
				b[j][i] = aa[c];
				if(r == aa[c]){
					cout << i << ' ' << j;
					return 0;
				}
				c++;
			}
		}
	}
	return 0;
}
