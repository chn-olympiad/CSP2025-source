#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in ","r",stdin);
	freopen("club.out ","w",stdout);
	long long l;
	cin>>l;
	long long n;
	int a[4],b[3];
	long long k[100000];
	int e=0;
	for(int i=1;i<=l;i++){
		cin>>n;
		for(int y=1;y<=n;y++){
			for(int j=1;j<=3;j++){
				cin>>a[i];
				if(n>3){
					sort(a+1,a+1+3);
					e+=a[1];
				}else{
					if(n<3){
						e+=(a[1]+a[2]+a[3])/3;
					}
				}
				}
			
			}
		}
		
	
	cout<<e;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
