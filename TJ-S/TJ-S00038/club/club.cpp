#include<bits/stdc++.h>
using namespace std;
int a[10][100005];
int b[8];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int c=0;
		for(int j=0;j<n;j++){
			cin>>a[0][j]>>a[1][j]>>a[2][j];
		}
		for(int j=0;j<3;j++){
			b[j]=0;
		}
		for(int j=0;j<n;j++){
			if(a[0][j]>=a[1][j]&&b[0]<n/2){
				if(a[0][j]>=a[1][j]){
					int no=0;
					for(int k=i;k<n;k++){
						if(a[0][j]<a[0][k]){
							no++;
						}
					}
					if(no==0){
						c+=a[0][j];
						b[0]++;
					}
				}else if(a[0][j]<a[1][j]&&b[1]<n/2||a[0][j]>=a[1][j]&&b[1]<n/2){
					int no=0;
					for(int k=i;k<n;k++){
						if(a[1][j]<a[1][k]){
							no++;
						}
					}
					if(no==0){
						c+=a[1][j];
						b[1]++;
					}
				}
			}else if(a[0][j]<a[1][j]&&b[1]<n/2||a[0][j]>=a[1][j]&&b[1]<n/2){
				if(a[1][j]>=a[2][j]){
					int no=0;
					for(int k=i;k<n;k++){
						if(a[1][j]<a[1][k]){
							no++;
						}
					}
					if(no==0){
						c+=a[1][j];
						b[1]++;
					}
				}else if(a[1][j]<a[2][j]&&b[2]<n/2||a[1][j]>=a[2][j]&&b[2]<n/2){
					int no=0;
					for(int k=i;k<n;k++){
						if(a[2][j]<a[2][k]){
							no++;
						}
					}
					if(no<n/2){
						c+=a[2][j];
						b[2]++;
					}	
				}
			}
		}
		cout<<c<<endl;
	}
	return 0;
}
