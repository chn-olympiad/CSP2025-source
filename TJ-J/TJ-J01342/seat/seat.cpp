#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int b[1000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;//R表示小R的座位 
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	R=a[1][1]; 
	int cnt=1;
	//b数组的下标 
	for(int j=1;j<=m;j++){//共有m列 
		for(int i=1;i<=n;i++){//每列n个人 
			if(j%2==1){
				b[cnt]=a[i][j];
			} 
			else
				b[cnt]+=a[i][m-j+1];
			cnt++;
		}
	}
	cnt=1;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n*m;i++){
		
		if(b[i]==R){
			if(i%n==0)
				cout<<i%n+n<<" ";
			else
				cout<<i%n<<" ";
				
				
			if(i%2==1)
				cout<<i%m+1;
			else cout<<n-i%m;
			
			return 0;
		}
		
	}
	return 0;
} 
