#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,cnt=1,y=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	x=b[1];
	sort(b,b+n*m+1);
	if(n%2!=0){
		y=m;
	}
	for(int i=n;i>=1;i--){
		if(i%2==0){
			for(int j=1;j<=m;j++){
				a[i][j]=b[cnt];
				cnt++;
			}
		}if(i%2!=0){
			for(int j=m;j>=1;j--){
				a[i][j]=b[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x==a[i][j]){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
