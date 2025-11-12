#include<iostream>
using namespace std;
int n,m,s[105][105],a[105],x=1,aaa,AAA;
bool xx=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	AAA=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i;j<=n*m;j++){
			if(a[j]>a[i]){
				aaa=a[i];
				a[i]=a[j];
				a[j]=aaa;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(xx){
			for(int j=n;j>=1;j--){
				s[i][j]=a[x];
				x++;
				xx=0;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				s[i][j]=a[x];
				x++;
				xx=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]==AAA){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
