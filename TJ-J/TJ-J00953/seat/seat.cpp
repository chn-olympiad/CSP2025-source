//#Shang4Shan3Ruo6Shui4 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int b[35];
int a[15][15],ans[15][15]; 
queue<int>q;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int num=a[1][1];
	sort(a*a+1,a*a+1+n+m,cmp); 
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				if(a[i][j]==num)cout<<i<<" "<<j;
			}
		}
		else {
			for(int i=1;i<=n;i++){	
				if(a[i][j]==num)cout<<i<<" "<<j;
			}
		}
	}
	
	return 0;
}

