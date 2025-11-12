#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m,c,a[N],s[N][N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				s[j][i]=a[j];
			}
		}else{
			for(int j=m;j>=1;j--){
				s[j][i]=a[j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==c){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
