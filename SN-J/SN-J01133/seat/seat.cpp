#include <bits/stdc++.h>

using namespace std;
struct oi{
	int x,num;
}a[1000][1000],k[1000000];
int n,m;
bool cmp(oi x,oi y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n>>m;
	for(int i=0;i<n*m;i++){
		cin >> k[i].x;
		k[i].num=i;
	}
	int f=0;
	sort(k,k+(n*m),cmp);
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				a[j][i]=k[f];
				f++;
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				a[j][i]=k[f];
				f++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
//			cout << a[i][j].x<<' ';
			if(a[i][j].num==0){
				cout << j+1<<' '<<i+1;
				return 0;
			}
		}
//		cout << endl;
	}
}
