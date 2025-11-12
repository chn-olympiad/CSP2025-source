#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	int b[12][12];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	int cnt=0;
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				b[i][j]=a[++cnt];
				if(b[i][j]==R){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[++cnt];
				if(b[i][j]==R){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		
	}
	return 0;
}
