#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[104]={},r,ans=1;
	int s[15][15]={};
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				s[i][j]=a[ans];
				ans++;
			}	
		}
		else{
			for(int j=1;j<=n;j++){
				s[i][j]=a[ans];
				ans++;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]==r){
				cout<<i<<" "<<j;
			}
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
