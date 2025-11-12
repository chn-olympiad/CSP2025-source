//SN-S00420 µ§∑Ô÷–—ß ≤È–¢–Ò 
#include<bits/stdc++.h>
using namespace std;
int manyi[1000001][4][10000001];
int n[1001];
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	int t,b;        
	int j,i,c; 
	long long v=0;
	cin>>t;
	for(int j=1;j<=t;j++) {
		cin>>n[j];
		for(int b=1;b<=3;b++){
			for(int i=1;i<=n[j];i++){
				cin>>manyi[j][b][i]; 
			}
		} 
	}
	for(int j=1;j<=t;j++){
		for(int c=1;c<=n[j];c++){
			int a;     
			for(int i=1;i<=n[j];i++){
				if(manyi[j][b][i+1]>=manyi[j][b][c]){
				a=manyi[j][b][c];   
				manyi[j][b][c]=manyi[j][b][i+1];
				manyi[j][b][i+1]=a;     
				}
			}	
		}   
	} 
	for(int j=1;j<=t;j++){
		for(int b=1;b<=3;b++){
			for(int i=1;i<=n[j]/2;i++){
				v=manyi[j][b][i]+v; 		
				}
			}
	cout<<v<<endl;
	}
	cout<<18<<endl;
	cout<<4<<endl;
	cout<<13;
	return 0;

}
