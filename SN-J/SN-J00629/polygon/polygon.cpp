//SN-J00629 杨济铭 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int f=1;
	while(f){
		f=0;
		for(int i=1;i<n;i++){
			if(a[i]<a[i-1]){
				f=1;
				int t=a[i-1];
				a[i-1]=a[i];
				a[i]=t;
			}
		}
	}
//	int min=a[0],q;
//	for(int i=0;i<2;i++){
//		for(int j=0;j<n;j++){
//			if(a[j]>min){
//				min=a[j];
//				q=j;
//				break;
//			}
//		}
//	}
//	for(int i=q;i<n;i++)
	if(a[1]+a[2]>a[3]){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
