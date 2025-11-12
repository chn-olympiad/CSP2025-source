#include <bits/stdc++.h>
using namespace std;
int a[102];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int c,r,t,b[101][101];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1);
	int t1=1,t2=n*m;
	for(int i=1;i<=m;i++){
		if(t1<n){
			for(int j=1;j<=n;j++){
				b[i][j]=a[t2--];
				t1++;
			}
		}else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[t2--];
				t1--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==t){
				cout<<i<<" "<<j;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
