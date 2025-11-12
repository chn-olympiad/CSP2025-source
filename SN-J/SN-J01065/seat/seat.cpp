//SN-J01065 郭子羽 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
int n,m,x,l,r,len,a[1010];
bool flag;
bool cmp(int a,int b){
	return a > b;
} int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	len = n * m;
	for(int i = 1;i <= len;i++){
		cin >> a[i];
	} x = a[1];
	sort(a + 1,a + len + 1,cmp);
	l = 1; r = 0;
	for(int i = 1;i <= len;i++){
//		cout << i << " " << a[i] << "\n";
		if(l % 2){
			r++;
			if(r > n){
				l++;
				r = n;
			} 
		}else{
			r--;
			if(r < 1){
				l++;
				r = 1;
			} 
		}
		if(a[i] == x) break;
	}
	cout << l << " " << r;
	return 0;
}//复杂度O(n*m)，预计100
