#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	int aa[11][11];
	cin>>n>>m;
	int q[101]={0};
	int a[101];
	int w=m*n;
	int ss;
	for(int i=0;i<w;i++){
		cin>>a[i];
		q[a[i]]++;
	}
	int s=0;
	ss=a[0];//ss用于记录小R成绩 
	for(int i=0;i<101;i++){
		if(q[100-i]>0){
			a[s]=100-i;
			s++;
		}
	}
	int x=0,y=0;
	for(int i=0;i<w;i++){
		if(x%2==1){//奇数列时 
			y++;
			if(y>m){
				y-=1;
				x++;
			}
		}else{//偶数列时 
			y--;
			if(y<1){
				y=1;
				x++;
			}
		}
		if(a[i]==ss){
			cout<<x<<" "<<y;
		}
	}
	 
	fclose(stdin);
	fclose(stdout);
}

 
 
