#include<bits/stdc++.h>
using namespace std;
int k;//cishu
int n,sa,sb,sc;
int bjc,ix=0;
int a[200005],c[200005],b[200005],d[200005][15];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>k;
	int num=0;
	for(int l=0;l<k;l++){
		num=0;n=0;
		cin>>n;
		for(int i=0;i<=max(sa,max(sb,max(sc,n)));i++){
			a[i]=0;
			b[i]=0;
			c[i]=0;
			d[i][1]=0;
			d[i][2]=0;
			d[i][3]=0;
			d[i][4]=0;
			d[i][5]=0;
			d[i][6]=0;
			d[i][7]=0;
			d[i][8]=0;
		}sa=0;sb=0;sc=0;bjc=0;ix=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=d[i][1]) {
				d[i][1]=a[i];
				d[i][2]=1;
			}
			if(b[i]>=d[i][1]) {
				d[i][1]=b[i];
				d[i][2]=2;
			}
			if(c[i]>=d[i][1]) {
				d[i][1]=c[i];
				d[i][2]=3;
			}//reach the max one and the group of the max one
//	----------------------------------------------------
			
			if(d[i][1]==a[i]){
				if(d[i][1]-b[i] >= d[i][1]-c[i]){
					d[i][3] = d[i][1]-c[i];
//					d[i][4] = 3;
				}else{
					d[i][3] = d[i][1]-b[i];
//					d[i][4] = 2;
				}
				d[d[i][3]][6]++;
				sa=max(sa,d[i][3]);
			}
			
			
			if(d[i][1]==b[i]){
				if(d[i][1]-a[i] >= d[i][1]-c[i]){
					d[i][3] = d[i][1]-c[i];
//					d[i][4] = 3;
				}else{
					d[i][3] = d[i][1]-a[i];
//					d[i][4] = 1;
				}
				d[d[i][3]][7]++;
				sb=max(sb,d[i][3]);
//				cout<<1<<endl;
			}
			
			
			if(d[i][1]==c[i]){
				if(d[i][1]-b[i] >= d[i][1]-a[i]){
					d[i][3] = d[i][1]-a[i];
//					d[i][4] = 1;
				}else{
					d[i][3] = d[i][1]-b[i];
//					d[i][4] = 2;
				}
				d[d[i][3]][8]++;
				sc=max(sc,d[i][3]);
			}
			
			//reacout<<s[i][3]<<endl;ch sa,sb,sc
//----------------------------------------------------------
//		for(int i=1;i<=n;i++){
//			d[d[i][3]][5]+=1;
//			if(s<d[i][3]) s==d[i][3];
//			num+=d[i][1];
//			cout<<d[i][1]<<endl;
		}
		
		for(int i=1;i<=n;i++){
			num+=d[i][1];
			if(d[i][1]==a[i]){
				a[0]++;continue;
			} 
			if(d[i][1]==b[i]) {
				b[0]++;continue;
			}
			if(d[i][1]==c[i]) {
				c[0]++;continue;
			}
		}
//		cout<<a[0]<< "   "<<b[0]<< "   "<<c[0]<<endl;
//		final number````````````````````````````````````````````````````````````````````````````
		if(a[0]>(n/2)){
			bjc=a[0]-(n/2);
			ix=1;
			while (3<4){
				
				if(d[ix][6]!=0){
					
					if(d[ix][6]>=bjc){
						num-=bjc*ix;
						break;
					}else{
						num-=d[ix][6]*ix;
						bjc-=d[ix][6];
					}
				}
				ix++;
			}
		}
		if(b[0]>(n/2)){
			bjc=b[0]-(n/2);
			ix=1;
			while (3<4){
				
				if(d[ix][7]!=0){
//					cout<<ix<<endl;
					if(d[ix][7]>=bjc){
						
						num-=bjc*ix;
						break;
					}else{
						num-=d[ix][7]*ix;
						bjc-=d[ix][7];
					}
				}
				ix++;
			}
		}
		if(c[0]>(n/2)){
			bjc=c[0]-(n/2);
			ix=1;
			while (3<4){
				
				if(d[ix][8]!=0){
					if(d[ix][8]>=bjc){
						num-=bjc*ix;
						break;
					}else{
						num-=d[ix][8]*ix;
						bjc-=d[ix][8];
					}
				}
				ix++;
			}
		}
		
//		``````````````````````````````````````````````````````````````````````````````````````````````		
		cout<<num<<endl;
//		
		
//		for(int i=1;i<=sa;i++){
//			d[i][1]=0;
//			d[i][2]=0;
//			d[i][3]=0;
//			d[i][4]=0;
//			d[i][5]=0;
//			d[i][6]=0;
//			d[i][7]=0;
//			d[i][8]=0;
//		}
//		for(int i=1;i<=sb;i++){
//			d[i][1]=0;
//			d[i][2]=0;
//			d[i][3]=0;
//			d[i][4]=0;
//			d[i][5]=0;
//			d[i][6]=0;
//			d[i][7]=0;
//			d[i][8]=0;
//		}
//		for(int i=1;i<=sc;i++){
//			d[i][1]=0;
//			d[i][2]=0;
//			d[i][3]=0;
//			d[i][4]=0;
//			d[i][5]=0;
//			d[i][6]=0;
//			d[i][7]=0;
//			d[i][8]=0;
//		}

		
	}
	
	
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
