#include<bits/stdc++.h>
using namespace std;
int a[1000],b[100][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin >> a[i];
	}
	int cj=a[1],cnta=1,h=1,l=1;//ÐÐ£¬ÁÐ 
	sort(a+1,a+nm+1,greater<int>());
	while(l<=m){
		if(l%2==1){
			b[h][l]=a[cnta];
			cnta++;
			if(h==n){
				l++;
			}else{
				h++;
			}
		}else{
			b[h][l]=a[cnta];
			cnta++;
			if(h==1){
				l++;
			}else{
				h--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==cj){
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
