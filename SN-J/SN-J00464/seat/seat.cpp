#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],x,nm,b[11][11],cnt=1;
int cmp(int a,int b){
	if(a>b){
		return 1;
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i]; 
	} 
	x=a[1];
	sort(a+1,a+nm+1,cmp);
//	for(int i=1;i<=nm;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				b[i][j]=a[cnt];
//				cout<<cnt<<" "<<a[cnt]<<" "<<i<<" "<<j<<" "<<b[i][j]<<endl;
				cnt++;
			}
		}else{
			for(int i=n;i>=1;i--){
				b[i][j]=a[cnt];
//				cout<<cnt<<" "<<a[cnt]<<" "<<i<<" "<<j<<" "<<b[i][j]<<endl;
				cnt++;
			}
		}
	}
//	cout<<endl<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			cout<<b[i][j]<<" ";
			if(b[i][j]==x){
				cout<<j<<" "<<i;
			}
		}
//		cout<<endl;
	}
	return 0;
}
