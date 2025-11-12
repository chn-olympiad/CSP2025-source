#include<bits/stdc++.h>
using namespace std;
int a[110];
int compare(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,c,r;
	cin>>n>>m;
	int sums=n*m;
	for(int i=1;i<=sums;i++){
		cin>>a[i];
	}
	int anss=a[1];
	sort(a+1,a+1+sums,compare);
	int ans[n+5][m+5];
	int num=1;//成绩数组的下标 
	for(int i=1;i<=m;i++){
		int hx=1;//行数 
		if(hx%2!=0){
			for(int j=1;j<=n;j++){
				ans[j][i]=a[num];
				num++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				ans[j][i]=a[num];
				num++;
			}
		}
		hx++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==anss){
				c=j;
				r=i;
			}
		}
	}
	cout<<c<<" "<<r<<endl;
	return 0;
} 

