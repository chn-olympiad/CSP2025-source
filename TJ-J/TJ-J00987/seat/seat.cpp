#include<bits/stdc++.h>
using namespace std;

int a[101];
int rx[101];
int zz[11][11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long b,c,d,n,m,e=0;
	//for(int i=0;i<=1000000;i++){
		cin>>n>>m;
		cin>>d;
		a[d]=d;
		b=n*m;
		for(int i=1;i<b;i++){
			cin>>c;
			a[c]=c;
		}
		
	for(int j=100;j>0;j--){
		
			for(int x=1;x<=b;x++){
				rx[x]=a[j];
				
			}
			
		}
	for(int l=1;l<=b;l++){
		if(rx[l]==d){
			e=d;
		}
		
	}
	int zza=0;
	for(int xx=1;xx<=m;xx++){
		
		for(int yy=1;yy<=n;yy++){
			zza+=1;
			//for(int l=1;l<=b;l++){
				zz[yy][xx]=zza;
			//}
		
		}
			
	}
	for(int xa=1;xa<=m;xa++){
		
		for(int ya=1;ya<=n;ya++){
			if(zz[ya][xa]==e){
				cout<<ya<<' '<<xa;
				return 0;
			}
				
		
		}
			
			
	}	
		
		
		
	
	
	
return 0;	
}
