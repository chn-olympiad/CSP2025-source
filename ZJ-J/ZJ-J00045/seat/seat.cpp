#include<bits/stdc++.h>
using namespace std;
const int N=500;
int a[N];
int b[N][N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int need=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1;
	bool flag=true;
	int cn=1;
	b[i][j]=a[1];
	while(1){
		cn++;
		if((i==n-1&&j%2==1)){
			i++;
			b[i][j]=a[cn];
			j++;
			cn++;
			if(m*n<cn){
				break;
			}
			b[i][j]=a[cn];
			flag=false;
		}
		else if((i==2&&j%2==0)){
			i--;
			b[i][j]=a[cn];
			j++;
			cn++;
			if(m*n<cn){
				break;
			}
			b[i][j]=a[cn];
			flag=true;
		}
		else if(flag==true){
			i++;
			b[i][j]=a[cn];
		}
		else{
			i--;
			b[i][j]=a[cn];	
		}	
		if(m*n<cn){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==need){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
