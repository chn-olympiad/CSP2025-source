#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int b[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nm;
	cin>>n>>m;
	nm=n*m;
	int rr;
	for(int i=1;i<=nm;i++){
		cin>>b[i];
	}
	rr=b[1];
	sort(b+1,b+nm+1,cmp);

	int pos=1;
	bool v=false;
	for(int i=1;i<=m;i++){
		if(i%2==0){
//			cout<<i;
			for(int j=n;j>0;j--){
//				cout<<j<<" ";
				a[i][j]=b[pos];
				pos++;
				if(a[i][j]==rr){
					cout<<i<<" "<<j;
					v=true;
					break;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				a[i][j]=b[pos];
				pos++;
				if(a[i][j]==rr){
					cout<<i<<" "<<j;
					v=true;
					break;
				}
			}
		}
		if(v==true){
			break;
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}
