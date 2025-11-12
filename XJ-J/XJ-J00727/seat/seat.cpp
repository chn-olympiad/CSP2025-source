#include<bits/stdc++.h>
using namespace std;
int n,m,a[101]/*a[1]为小R的分数，a[0]不计数*/,x/*小R的分数*/,y/*小R的序号*/;
int main(){
	//录入
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+(n+m)+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			y=i;
		}
	}
	int k=0/*运行到第k名*/;
	for(int i=1;i<=m;i++){
		//向下
		if(i%2==1){
			for(int j=1;j<=n;j++){
				
				if(k==y){
					cout<<j<<" "<<i;
					return 0;
				}
				k++;
			}
		}
		if(i%2==0){
			for(int j=n;j>0;j--){
				
				if(k==y){
					cout<<j<<" "<<i;
					return 0;
				}
				k++;
			}
		}
	}
}
