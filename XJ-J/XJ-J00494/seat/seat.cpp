#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	int pm=1;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i>0&&a[i]>a[0]) pm++;
	}
	int ans[n][m];
	int cnt=1;
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				ans[j][i]=cnt;
				cnt++;
			}
		}else{
			for(int j=n-1;j>=0;j--){
				ans[j][i]=cnt;
				cnt++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ans[i][j]==pm) {
				cout<<j+1<<' '<<i+1;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
