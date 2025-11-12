#include<bits/stdc++.h>
using namespace std;
int a[100005],n,m,s[105][105],c=0,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				c++;
				s[i][j]=a[c];
				if(a[c]==r){
					cout<<i<<" "<<j;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				c++;
				s[i][j]=a[c];
				if(a[c]==r){
					cout<<i<<" "<<j;
				}
			}
		}
		
	}
	return 0;
}