#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n>> m;
	int a[n*m+101];
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	int s[n+1][m+1];
	int o=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				s[i][j]=a[o];
				if(a[o]==x){
					cout << i << " " << j;
					return 0;
				}
				o++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				s[i][j]=a[o];
				if(a[o]==x){
					cout << i << " " << j;
					return 0;
				}
				o++;
			}
		}
	}
	return 0;
} 
