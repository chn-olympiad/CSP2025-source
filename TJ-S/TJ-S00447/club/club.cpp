#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,c=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			if(a1>a2 && a1>a3){
				a[j]=a1;
			}else if(a2>a1 && a2>a3){
				a[j]=a2;
			}else if(a3>a2 && a3>a1){
				a[j]=a3;
			}
			c+=a[j]; 
		}
		b[i]=c;
		c=0;
	}
	for(int i=1;i<=t;i++){
		cout<<b[i]<<"\n";
	}
	return 0;
}

