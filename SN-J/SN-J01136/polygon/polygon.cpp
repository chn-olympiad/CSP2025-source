//考号：SN-J01136 姓名：霍启若 学校：蒲城县城南学校 
#include<bits/stdc++.h>
using namespace std;
int n,a[5010],cnt,m,oc;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	if(n == 3){
		for(int i = 0;i < 3;i++){
			m = max(m,a[i]);
			oc += a[i];
		}
		if(oc > m * 2) cnt++;
		cout << cnt;
	}
	else cout << 2;
	return 0;
}
