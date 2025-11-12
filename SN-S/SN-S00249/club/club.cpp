#include<bits/stdc++.h>
//using namespace std;
std::ifstream cin("club.in");
std::ifstream cout("club.out");
int z1(int a,int b,int c){
	int c2=0;
	c2=max(max(a,b),max(b,c));
}
int main(){
	int n=0,gg=0;
	cin>>n;
	int z=0,x1=0,x2=0,x3=0,t1=0,t2=0,t3=0,ans=0;

	for(int i=0;i<n;i++){
		cin>>z;
		gg=n;
		int mm=z,mm2=z;
		int a[z][3]={};
//		while(mm--){
//			
//		}

		while(mm2--){
			
			cin>>a[i][0]>>a[i][1]>>a[i][2];
	 		if(z1(a[i][0],a[i][1],a[i][2])==a[i][0]){
	 			if(x1<=z/2){
	 				x1++;
	 				t1=max(a[i][0],t1);
				 }else if(max(a[i][1],a[i][2])==a[i][1] and x2<=z/2){
				 	x2++;
				 	t2=max(a[i][1],t2);
				 }else{
				 	x3++;
				 	t3=max(a[i][2],t3);
				 }
			 }else if(z1(a[i][0],a[i][1],a[i][2])==a[i][1]){
	 			if(x2<=z/2){
	 				x2++;
	 				t2=max(a[i][1],t2);
				 }else if(max(a[i][1],a[i][2])==a[i][0] and x1<=z/2){
				 	x1++;
				 	t1=max(a[i][0],t1);
				 }else{
				 	x3++;
				 	t3=max(a[i][2],t3);
				 }
			 }else if(z1(a[i][0],a[i][1],a[i][2])==a[i][2]){
	 			if(x3<=z/2){
	 				x3++;
	 				t3=max(a[i][2],t3);
				 }else if(max(a[i][1],a[i][2])==a[i][1] and x2<=z/2){
				 	x2++;
				 	t2=max(a[i][1],t2);
				 }else{
				 	x1++;
				 	t1=max(a[i][0],t1);
				 }
			}
 			
		}
		ans=t1+t2+t3;
		cout<<ans;
	}
	
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

