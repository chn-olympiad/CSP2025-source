#include<bits/stdc++.h>
using namespace std;
int n,m;
int a1[1007][1007];
int a[100007];
int k; 

int ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n*m;i++){
		cin >>a[i];
		k++;
	}
	ans=a[1];
	sort(a+1,a+n*m+1);
	int u=1;//标记为那种写入方式 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a1[i][j]==0;
		}
	} 
	for(int j=1;j<=m;j++){//第几列 
		if(u==1){							//从上到下 
			for(int i=1;i<=n;i++){//读入的数值 的新位置 
				a1[i][j]=a[k];
				k--;
			}
			u=2;	
		}else if(u==2){						//从下到上 
			for(int i=n;i>=1;i--){//读入的数值 的新位置 
				a1[i][j]=a[k];
				k--;
			}
			u=1;
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a1[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	 

	return 0;
} 
