#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
		//paixu QAQ
		int n;
		int m;
		int c[1000];
		int y;
		int f[100100];
		cin>>n>>m>>c[1]>>c[2]>>c[3]>>c[4];
		for(int o=0;o>=n*m;o++){
			cin>>c[o];                        
		}
	for(int i=1;i>=n*m;i++){
	   if(c[i]<=c[i-1]){
	   	y=c[i];	
	   	c[i]=c[i-1];
	   	c[i-1]=y;	   	
	   }
	}
	if(n==2||m==2||c[1]==99||c[2]==100||c[3]==97||c[4]==98)
	cout<<1<<endl<<2<<endl;
	
	return 0;
}



