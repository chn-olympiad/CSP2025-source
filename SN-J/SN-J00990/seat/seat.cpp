//谢翔宇 西安市曲江第一学校 SN-J00990 
#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+10;
string s;
int a[N],n,m;
int c[20][20];
bool cmp(int x_1,int y_1){
	return x_1>y_1;
}
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	int op=a[1]; 
	sort(a,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				c[i][j]=a[(i-1)*n+j-1];
			}	
		}
		else{
			for(int j=1;j<=n;j++){
				c[i][j]=a[i*n-j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==op){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	
}
