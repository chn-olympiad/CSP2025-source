#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],num[20][20],x=1,ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			num[i][j]=a[x];
			x++;
		}
		i++;
		for(int j=m;j>=1;j--){
			num[i][j]=a[x];
			x++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(num[i][j]==ans){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
