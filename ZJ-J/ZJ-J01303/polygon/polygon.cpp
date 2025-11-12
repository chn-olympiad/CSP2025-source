#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int maxx=*max_element(a+1,a+n+1);
	if(maxx==1){
		int sum=0;
		for(int i=1;i<=n-2;i++){
			int cheng=1;
			int chu=1;
			for(int j=n;j>=i;j--){
				cheng*=j;
			}
			for(int j=1;j<=n-i+1;j++){
				chu*=j;
			}
			cout<<cheng<<" "<<chu<<endl;
			sum+=cheng/chu;
		}
		cout<<sum;
	}	
	else{
		if(n<3){
			cout<<0;
		}	
		else if(n==3){
			if(a[1]+a[2]>a[3]){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else if(n==4){
			int q=0;
			if(a[1]+a[2]>a[3]){
				q+=1;
			}
			if(a[1]+a[3]>a[4]){
				q+=1;
			}
			if(a[2]+a[3]>a[4]){
				q+=1;
			}
			if(a[1]+a[2]>a[4]){
				q+=1;
			}
			if(a[1]+a[2]+a[3]>a[4]){
				q+=1;
			}
			cout<<q;
		}
		else if(n==5){
			int q=0;
			if(a[1]+a[2]>a[3]){
				q+=1;
			}
			if(a[1]+a[2]>a[4]){
				q+=1;
			}
			if(a[1]+a[2]>a[5]){
				q+=1;
			}
			if(a[1]+a[3]>a[4]){
				q+=1;
			}
			if(a[1]+a[3]>a[5]){
				q+=1;
			}
			if(a[1]+a[4]>a[5]){
				q+=1;
			}
			if(a[2]+a[3]>a[4]){
				q+=1;
			}
			if(a[2]+a[3]>a[5]){
				q+=1;
			}
			if(a[2]+a[4]>a[5]){
				q+=1;
			}
			if(a[3]+a[4]>a[5]){
				q+=1;
			}
			if(a[1]+a[2]+a[3]>a[4]){
				q+=1;
			}
			if(a[1]+a[2]+a[3]>a[5]){
				q+=1;
			}
			if(a[1]+a[2]+a[4]>a[5]){
				q+=1;
			}
			if(a[1]+a[3]+a[4]>a[5]){
				q+=1;
			}
			if(a[2]+a[3]+a[4]>a[5]){
				q+=1;
			}
			if(a[1]+a[2]+a[3]+a[4]>a[5]){
				q+=1;
			}
			cout<<q;
		}
	}
	return 0;
}
