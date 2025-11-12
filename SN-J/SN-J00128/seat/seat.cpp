#include<bits/stdc++.h>
using namespace std;
int n,m,a[10050][10005],b[10005],v,num,d,sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	v=b[1];
//	num=n*m;
	for (int i=1;i<=n*m;i++){
		for (int j=1;j<=n*m;j++){
			if (b[j]<b[j+1]){
				d=b[j+1];
				b[j+1]=b[j];
				b[j]=d;
			}
		}
	}	
//	for (int i=1;i<=m;i++){
//		for (int j=1;j<=n;j++){
//			num++;
//			a[i][j]=b[num];
//		}
//	}
	for (int i=1;i<=m;i++){
		sum++;
		if (sum%2==0){
			for (int j=n;j>=1;j--){
				num++;
				a[i][j]=b[num];
			}	
		}else{
			for (int j=1;j<=n;j++){
				num++;
				a[i][j]=b[num];
			}
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			if (a[i][j]==v){
				cout<<i<<" "<<j;
				return 0;
			}
			
//			cout<<a[i][j]<<" ";
		}
//		cout<<endl;
	}
	return 0;
}
