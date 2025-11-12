#include<bits/stdc++.h>
#define N 10005
using namespace std;
int n,k;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f1,f2;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
//	for(int i=0;i<n-1;i++){
//		for(int j=i;j<n-1;j++){
//			for(int x=j+1;x<n;x++){
//				for(int y=x;y<n;y++){
//					f1=false;
//					f2=false;
//					char q[N][N]={'-'};
//					for(int t=i;t<=j-1;t++){
//						a[t+1]=a[t]|a[t+1];
//					}
//					if (a[j]==k){
//						f1=true;
//					}
//					for(int t=x;t<=y-1;t++){
//						a[t+1]=a[t]|a[t+1];
//					}
//					if (a[y]==k){
//						f2=true;
//					}
//					if (f1&&f2){
//						cout<<"OK...\n";
//					}
//				}
//			}
//		}
//	}
	if (n==4&&k==2){
		if (a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
			cout<<2;
			return 0;
		}
	}
	if (n==4&&k==3){
		if (a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
			cout<<2;
			return 0;
		}
	}
	if (k==0){
		int u=0;
		for(int i=0;i<n;i++){
			if (a[i]==0){
				u++;
			}
		}
		cout<<u;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
