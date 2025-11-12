#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000][1000]={0};
int main(){
	int n,m,s,x=1,y=1,ans=0,temp;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		s=a[1];
	}
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]<a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=1;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(ans=0){
			if(b[x][y+1]!=0){
				y+=1;
				b[x][y]=a[i];
			}else{
				x+=1;
				b[x][y]=a[i];
				ans=(ans+1)%2;
			}
		}else if(ans=1){
			if(b[x][y-1]!=0){
				y-=1;
				b[x][y]=a[i];
			}else{
				x+=1;
				b[x][y]=a[i];
				ans=(ans+1)%2;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<b[i][j]; 
		} 
		cout<<endl;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			if(b[i][j]==s){
//				cout<<i<<j;
//			}
//		}
//	}
}
