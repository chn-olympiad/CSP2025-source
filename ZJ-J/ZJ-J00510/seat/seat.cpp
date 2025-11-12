#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int r = 0;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	r = a[1];
	int x = n * m;
	sort(a+1,a+1+x,cmp);
//	for(int i = 1;i <= x;i++) cout << a[i] << ' ';
	int tot = 1;
	for(int j = 1;j <= n;j++){// j lie
		if(j % 2 == 1){//cong xiao dao da
			for(int i = 1;i <= m;i++){
				if(a[tot] == r){
					cout << j << ' ' << i << endl;
					return 0;
				}
				tot++;
			}
		}else{
			for(int i = m;i >= 1;i--){
				if(a[tot] == r){
					cout << j << ' ' << i << endl;
					return 0;
				}
				tot++;
			}
		}
	}
	return 0;
}