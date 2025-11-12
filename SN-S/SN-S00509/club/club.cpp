#include<bits/stdc++.h>
using namespace std;
long long n;
long long b[100005];
long long a[10005][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
		cin>>n;
		for(long long int i=0;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(long long int i=1;i<=n;i++){
			long long int s=0,x=0,y=0;
			if(a[i][1]>a[i][3]&&a[i][1]>a[i][2]){
				s=0;
				if(a[i][2]>a[i][3]){
					x=0;
					y=2;
				}
				else{
					x=1;
					y=3;
				}
			}
				else{
					s=3;
					if(a[i][1]>=a[i][2]){
						x=1;
						y=2;
					}
					else{
						x=2;
						y=1;
					}
				}
				b[i][1]=s;
				b[i][2]=x;
				b[i][3]=y;                                                  
				
		}
		cout<<s<<x<<y;
		return 0;
	}
}dd
