/*
祁杨  SN-J00846 西安市曲江第一学校
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int r;
int a[20][20];
int b[110];
int num;
int x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num = n*m;
	for(int i = 1;i<=num;i++){
		cin>>b[i];
	}
	r = b[1];
	sort(b+1,b+1+num);
//	int ans = num;
//	for(int j = 1;j<=num;j++){
//		cout<<b[j]<<" ";
//	}
//	cout<<"\n\n\n";
//	for(int i = 1;i<=n;i++){
//		if(i%2 != 0){
//			for(int j = 1;j<=m;j++){
//				a[j][i] = b[ans];
//				--ans;
//				cout<<ans<<" ";
//			}
//		}else{
//			for(int j = m;j>=0;j--){
//				a[j][i] = b[ans];
//				--ans;
//				cout<<ans<<" ";
//			}
//		}
//	}
//	cout<<"\n";
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=m;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=m;j++){
//			if(r == a[i][j]){
//				cout<<j<<" "<<i;
//				return 0;
//			}
//		}
//	}
	for(int i = 1;i<=num;i++){
		if(r == b[i]){
			x = i;
			break;
		}
	}
	
	x = num-x+1;
	int q;
	if(x%m==0){
		q = x/m;
	}else{
		q = x/m+1;
	}
	cout<<q<<" ";
	if(q%2==0){
		cout<<m-(x-(q-1)*m)+1;
	}else{
		cout<<x-(q-1)*m;
	}
	return 0;
}

