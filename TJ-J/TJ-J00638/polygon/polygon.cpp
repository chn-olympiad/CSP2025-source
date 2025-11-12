#include<iostream>
using namespace std;
int a[5005];
bool pd(int i,int j){
	int sum=0,maxx=0;
	for(int x=j,y=1;y<=i;y++,x++){
		sum+=a[x];
		if(a[x]>maxx) maxx=a[x];
	}
	if(sum>maxx*2) return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	//for(int i=3;i<=n;i++){//iÊÇ³¢ÊÔ¼¸¸öÄ¾¹÷
	//	 for(i)
//	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			///cout<<"³¢ÊÔ"; 
			///for(int x=j;x<=i+j-1;x++){
			////	cout<<x<<',';
			/////}////
			///////////////////////////cout<<endl;
			if(pd(i,j)) cnt=(cnt+1)%998244353;
		}
	}
	cout<<cnt*2-cnt%2-1;
	return 0;
}
