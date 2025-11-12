#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int x=101;
	int t=0,f=0;
	cin>>n>>m;
	int b[n][m];
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	if(m%2==1)cout<<n<<" "<<m;
	if(m%2==0)cout<<1<<" "<<m;
//	for(int i=0;i<n*m;i++){
//		int q=0;
//		for(int j=0;j<n*m;j++){
//			if(a[j]>q&&a[j]<x){
//				q=a[j];
//			}
//		}
//		b[t][f]=q;
//		x=q;
//		if(q==a[0])cout<<t+1<<" "<<f+1;
//		if(t+1<n&&f%2==0){
//			t++;
//		}
//		if((t+1==n&&f%2==0)||(t-1<0&&f%2==1)){
//			f++;
//		}
//		if(t-1>0&&f%2==1){
//			t--;
//		}
//		
//	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			cout<<b[i][j]<<" ";
////			if(b[i][j]==a[0]){
////				cout<<i+1<<" ";
////				break;
////			}
//		}
//		cout<<endl;
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
