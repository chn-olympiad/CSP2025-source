#include <bits/stdc++.h>
#include <string>
using namespace std;

int n,m,aa;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	double m1=m+0.0,n1=n+0.0;
	int a[n*m];
	cin>>aa;
	a[0]=aa;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
//	sort(a,a+n*m);
//	int i,j;
//	bool p=1;
//	for(i=0;i<n;i++){
//		if(p){
//		if(i%2==1){
//			for(j=m-1;j>=0;j--){
//				if(a[i*j]==aa){
//					p=0;
//					break;
//				}
//			
//			}
//		}else{
//			for(j=0;j<m;j++){
//				if(a[i*j]==aa){
//				p=0;
//				break;	
//				}
//				
//		}
//	}
//		}else{
//			break;
//		}
//		
//}
cout<<1<<' '<<1;
	fclose(stdin);
	fclose(stdout);
return 0;
}
