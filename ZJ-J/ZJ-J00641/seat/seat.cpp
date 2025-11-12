#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int xm=a[1];
	int cnt;
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1; i <= n*m; i++){
//		cout << a[i] << ' ';
		if(a[i]==xm){
			cnt=i;
			break;
		}
	}
//	cout << '\n';
//	cout << cnt << '\n';
	int cnt2=0;
	for(int i = 1; i <= m; i++){
		if(i%2==1){
			for(int j = 1; j <= n; j++){
				cnt2++;
				if(cnt2==cnt){
					cout << i << ' ' << j;
					return 0;
				}
			}
		}else{
			for(int j = n; j >= 1; j--){
				cnt2++;
				if(cnt2==cnt){
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
}
