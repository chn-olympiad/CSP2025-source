// 张书瑞 SN-S00198 西安铁一中滨河学校中学
#include <bits/stdc++.h>
const int N=1005;
int a[N][N];
int b[N];
long long t,n,sum=0;
using namespace std;
int main(){
	
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		long long rs=n/2;
		for(int x=1;x<=n;x++){
		    for(int y=1;y<=3;y++){
		    	cin>>a[x][y];
			}
		}
		for(int x=1;x<=n;x++){
		    for(int y=1;y<=3;y++){
		    	for(int j=1;j<=n;j++){
		    		sum=sum=a[j][y]; 
				}
				
				
				cout<<sum<<" ";
			}
			
		}	
		
		
		
	
	
	
	}
	
	return 0;
}
