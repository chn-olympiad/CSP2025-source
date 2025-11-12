#include <bits/stdc++.h>
using namespace std;
int n,m,r;
int a[105];
int mp[15][15];
bool cmp(int x,int y){
	return x>y; 
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	int sum=0;
	sort(a+1,a+n*m+1,cmp);
	int cnt=1; 
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				mp[j][i]=a[cnt];
				cnt++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				mp[j][i]=a[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==r){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

	
