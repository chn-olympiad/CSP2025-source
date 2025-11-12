#include<bits/stdc++.h>
using namespace std;
bool asd(int x,int y){
	return x>y;
}
int a[105],b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	t=a[0];
	int cnt=0;
	sort(a,a+n*m,asd);
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				b[j][i]=a[cnt];
				cnt++;
			}
		}else{
			for(int j=n-1;j>=0;j--){
				b[j][i]=a[cnt];
				cnt++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[i][j]==t){
				cout<<j+1<<" "<<i+1;
			}
		}
	}
	return 0;
} 
