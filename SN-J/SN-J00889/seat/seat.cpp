#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	int cnt = 1;
	int cj;
	cin >> cj;
	for(int i =2;i<= n*m;i++){
		int x;cin >> x;
		if (x > cj){
			cnt++;
		}
	}
	//int lie = cnt/n + (cnt%n != 0);
	for(int i =1;i<= m;i++){
		if(i % 2 == 1){
			for(int j = 1;j<=n;j++){
				cnt--;
				//cout << cnt2 << " " << i << " " << j << endl;
				if(cnt <= 0) {
					cout << i << " " << j;
					return 0;
				}
			}
		}else{
			for(int j = n;j>=1;j--){
				cnt--;
				//cout << cnt2 << " " <<  i << " " << j << endl;
				if(cnt <= 0) {
					cout << i << " " << j;
					return 0;
				}
			}
		} 
		
	}
	return 0;
}
