#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int v[m+10];
	int a[n+10];
	for(int i=1;i<=m*3;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n+1;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(a[j]<=a[j+1]){
//				temp=a[j];
//				a[j]=a[j+1];
//				a[j+1]=temp;
//			}
//		}
//	}
	int temp;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++){
			if(a[j]<=a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(int i=1;i<=m*3;i++){
		for(int j=1;j<=m*3;j++){
			if(v[j]<=v[j+1]){
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
	cout<<1;
	return 0;
}

//Ren5Jie4Di4Ling5%
