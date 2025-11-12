#include <iostream>
#include <cstdio>
using namespace std;
int a[100005][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int js=0,cg=0;
		for(int j=1;j<=n;j++){
			cg=0;
			for(int p=1;p<=3;p++){
				cin>>a[j][p];
				if(cg<a[j][p]){
					cg=a[j][p];
				}				
			}
			js=js+cg;
		}
		cout<<js<<endl;
	}
	return 0;
}
