#include<bits/stdc++.h>
using namespace std;		
int a[105];
int main(){
freopen("seat.in",r,stdin);
freopen("seat.out",w,stdout);
int m,n;
cin>>m>>n;
for(int i=0;i<n*m;i++){
cin>>a[i];}
int b=a[0];
int sum=1;
sort(a,a+n*m+1); 
for(int i=n*m;i>0;i--){
if(a[i]==b){
	break;
}
	sum++;

}
if(sum<=m){
cout<<1<<" "<<sum;	
}else if(sum>2*m&&sum<=3*m){
	cout<<3<<" "<<sum-2*m;
}else if(sum>4*m&&sum<=5*m){
	cout<<5<<" "<<sum-4*m;
	}else if(sum>6*m&&sum<=7*m){
	cout<<7<<" "<<sum-6*m;
	}else if(sum>8*m&&sum<=9*m){
	cout<<9<<" "<<sum-8*m;
	
}
	if(sum>m&&sum<=2*m){
	cout<<2<<" "<<sum-sum-sum+m+m+1;
}else if(sum>3*m&&sum<=4*m){
cout<<4<<" "<<sum-sum-sum+m+m+1;
	}else if(sum>5*m&&sum<=6*m){
cout<<6<<" "<<sum-sum-sum+m+m+1;
	}else if(sum>7*m&&sum<=8*m){
cout<<8<<" "<<sum-sum-sum+m+m+1;
	}else if(sum>9*m&&sum<=10*m){
cout<<10<<" "<<sum-sum-sum+m+m+1;
}
}

