#include<bits/stdc++.h>
using namespace std;
struct Tx{
	long long d1,d2,d3,bj;
}tx[100010];
long long sum=0;
long long sum1,sum2,sum3;
bool cmp1(Tx x1,Tx y1){
	if(x1.d1==y1.d1) return x1.d2>y1.d2;
	else if(x1.d2==y1.d2) return x1.d3>y1.d3;
	return x1.d1>y1.d1;
}
bool cmp2(Tx x2,Tx y2){
	if(x2.d2==y2.d2) return x2.d1>y2.d1;
	else if(x2.d1==y2.d1) return x2.d3>y2.d3;
	return x2.d2>y2.d2;
}
bool cmp3(Tx x3,Tx y3){
	if(x3.d3==y3.d3) return x3.d2>y3.d2;
	else if(x3.d2==y3.d2) return x3.d1>y3.d1;
	return x3.d3>y3.d3;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,ts1=0,ts2=0,ts3=0;
	cin>>t;
	while(t!=0){
		t--;
		cin>>n;
		int no1=0,no2=0,no3=0;
		for(int i=1;i<=n;i++){
		cin>>tx[i].d1>>tx[i].d2>>tx[i].d3;
		sum1+=tx[i].d1;
		sum2+=tx[i].d2;
		sum3+=tx[i].d3;
		} 
		if(sum2==0&&sum3==0){
			sort(tx+1,tx+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				sum+=tx[i].d1;
			}
			cout<<sum<<"\n";
			continue;
		}
		if(sum1==0&&sum3==0){
			sort(tx+1,tx+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				sum+=tx[i].d2;
			}
			cout<<sum<<"\n";
			continue;
		}
		if(sum2==0&&sum1==0){
			sort(tx+1,tx+1+n,cmp3);
			for(int i=1;i<=n/2;i++){
				sum+=tx[i].d3;
			}
			cout<<sum<<"\n";
			continue;
		}
		if(n==2){
			
			sum=max(tx[1].d1+tx[2].d2,tx[1].d1+tx[2].d3);
			sum=max(sum,tx[1].d2+tx[2].d3);
			sum=max(sum,tx[1].d2+tx[2].d1);
			sum=max(sum,tx[1].d3+tx[2].d2);
			sum=max(sum,tx[1].d3+tx[2].d1);
			cout<<sum<<"\n"; 
			continue;
		}
		if(sum1<=sum2&&sum1<=sum3){//最小期望在1 
			sort(tx+1,tx+1+n,cmp1);
		//	cout<<tx[1].d1<<tx[2].d1;
			for(int i=1;i<=n;i++){
				if(no2==n/2&&tx[i].d1>=tx[i].d3||no3==n/2&&tx[i].d1>=tx[i].d2||no1!=n/2&&tx[i].d1>=tx[i].d2&&tx[i].d3<=tx[i].d1){
					sum+=tx[i].d1;
					no1++;
				} 
				else if(tx[i].d2>=tx[i].d3&&no2!=n/2||no3==n/2&&tx[i].d1<=tx[i].d2){
					sum+=tx[i].d2;
					no2++;
				} 
				else{
					sum+=tx[i].d3;
					no3++;
				}
			}
			cout<<sum<<"\n";
		}
		else if(sum1>sum2&&sum2<sum3){//2 
			sort(tx+1,tx+1+n,cmp2);
		//	cout<<tx[1].d1<<tx[2].d1;
			for(int i=1;i<=n;i++){
				if(no2==n/2&&tx[i].d2>=tx[i].d3||no3==n/2&&tx[i].d2>=tx[i].d1||no1!=n/2&&tx[i].d2>=tx[i].d1&&tx[i].d3<=tx[i].d2){
				sum+=tx[i].d2;
				no1++;	
				} 
				else if(tx[i].d1>=tx[i].d3&&no2!=n/2||no3==n/2&&tx[i].d2<=tx[i].d1){
					sum+=tx[i].d1;
					no2++;
				} 
				else{
					sum+=tx[i].d3;
					no3++;
			}}
			cout<<sum<<"\n";
		}
		else{//3 
		sort(tx+1,tx+1+n,cmp3);
		//	cout<<tx[1].d3<<tx[2].d3;
			for(int i=1;i<=n;i++){
				if(no2==n/2&&tx[i].d3>=tx[i].d2||no3==n/2&&tx[i].d3>=tx[i].d1||no1!=n/2&&tx[i].d1<=tx[i].d3&&tx[i].d3>=tx[i].d2){
				sum+=tx[i].d3;
				no1++;	
				} 
				else if(tx[i].d1>=tx[i].d2&&no2!=n/2||no3==n/2&&tx[i].d3<=tx[i].d1){
					sum+=tx[i].d1;
					no2++;
				} 
				else{
					sum+=tx[i].d2;
					no3++;
			}}
			cout<<sum<<"\n";
		}
		sum=0;
		sum1=sum2=sum3=0;
		
		no1=no2=no3=0;
	}
	return 0;
}
