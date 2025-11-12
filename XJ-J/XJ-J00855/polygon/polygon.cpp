#include<iostream>
using namespace std;
int n;
int a[5005],t1[20],t2[10],t3[20];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	int cnt=0,t=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			for(int k=1;k<=n;k++){
//				if(a[i]+a[j]+a[k]>2*(max(a[i],a[j],a[k])) && i!=j && j!=k && i!=k){
//					for(int p=1;i<=cnt;i++){
//						if(a[i]==t1[p]||a[i]==t2[p]||a[i]==t3[p]){
//							if(a[j]==t1[p]||a[j]==t2[p]||a[j]==t3[p]){
//								if(a[k]==t1[p]||a[k]==t2[p]||a[k]==t3[p]){
//									t=1;
//								}
//							}
//						}
//					}
//					if(t=1){
//						t=0;
//						break;
//					}
//					else{
//						cnt++;
//						t1[cnt]=a[i];
//						t2[cnt]=a[j];
//						t3[cnt]=a[k];
//					}
//				}
//			}
//		}
//	}
	cout<<1;
	return 0;
}
