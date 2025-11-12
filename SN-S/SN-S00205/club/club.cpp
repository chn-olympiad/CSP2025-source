#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int n,sum=0,k,i,j,t;
int main(){
	freopen("test.in","r",stdin);//张博涵  SN-S00205  陕西省丹凤中学   
	freopen("test.out","w",stdout);
	cin>>t;
	for(t=1;t<=5;t++){
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=3;j++){
			cin>>a[i,j];
		}
	}
	int club1[10000001];
	int club2[10000001];
	int club3[10000001];
	for(i=1;i<=n;i++){
		for(j=1;j<=3;j++){
		if(a[i,j]>a[i,j+1]&&a[i,j]>a[i,j+2]){
		    for(k=1;k<=(n/2);k++){
			club1[k]=a[i,j];
			}
	}else if(a[i,j+1]>a[i,j]&&a[i,j+1]>a[i,j+2]){
				for(k=1;k<=(n/2);k++){
					club2[k]=a[i,j+1];
				}
			}	else if(a[i,j+2]>a[i,j]&&a[i,j+2]>a[i,j+1]){
					for(k=1;k<=(n/2);k++){
						club3[k]=a[i,j+2];
					}
				}
			}
	}
	for(k=1;k<=(n/2);k++){
		sum=club1[k]+club2[k]+club3[k];
		}
		cout<<sum<<endl;
		}
		return 0;
}
