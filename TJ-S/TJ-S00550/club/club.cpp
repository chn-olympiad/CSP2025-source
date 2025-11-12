#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
	cin>>n;
	int a[n*3+10]={};
//	int b[n+10]={};
//	int c[n+10]={};
	for(int i=1;i<=n*3;i++){
		cin>>a[i];
	}
	 int sum=0;
	 int x1=0;
	 int x2=0;
	 int x3=0;
	for(int i=1;i<=n*3;i+=3){
//		cout<<i<<" ";
		if(a[i]<=a[i+1] && a[i+2]<=a[i+1]){
			if(x2+1<=n/2){
			sum+=a[i+1];
//			cout<<"b";
//			cout<<a[i+1];
			x2+=1;

			continue;
			}
		}
		if(a[i]<=a[i+2] && a[i+1]<=a[i+2]){
			if(x3+1<=n/2){
			sum+=a[i+2];
//			cout<<"c";
//			cout<<a[i+2];
			x3+=1;
			continue;
			}
		}
		if(x1+1<=n/2){
			sum+=a[i];
//			cout<<"a"<<endl;
			x1+=1;
		}
		if(x2+1<=n/2){
			sum+=a[i+1];
//			cout<<"b";
//			cout<<a[i+1];
			x2+=1;

			continue;
		}
		if(x3+1<=n/2){
			sum+=a[i+2];
//			cout<<"c";
//			cout<<a[i+2];
			x3+=1;
			continue;
			}
	}
	cout<<sum<<endl;
}
	return 0;
	}
/*
//	for(int x=1;x<=t;x++){
//		cin>>n;
//		int a[n+10][5]={};
//		for(int i=1;i<=n;i++){
//			cin>>a[i][1]>>a[i][2]>>a[i][3];
//		}
//	}
	cin>>n;
	int a[n*3+10]={};
//	int b[n+10]={};
//	int c[n+10]={};
	for(int i=1;i<=n*3;i++){
		cin>>a[i];
	}
//	int temp;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(a[j]<=a[j+1]){
//				temp=a[j];
//				a[j]=a[j+1];
//				a[j+1]=temp;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(b[j]<=b[j+1]){
//				temp=b[j];
//				b[j]=b[j+1];
//				b[j+1]=temp;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(c[j]<=c[j+1]){
//				temp=c[j];
//				c[j]=c[j+1];
//				c[j+1]=temp;
//			}
//		}
//	}
	 int sum=0;
	 int x1=0;
	 int x2=0;
	 int x3=0;
	for(int i=1;i<=n*3;i+=3){
		if(a[i]<=a[i+1] && a[i+2]<=a[i+1]){
			if(x2+1<=n/2){
			sum+=a[i+1];
//			cout<<"b";
//			cout<<a[i+1];
			x2+=1;

			continue;
			}
		}
		if(a[i]<=a[i+2] && a[i+1]<=a[i+2]){
			if(x3+1<=n/2){
			sum+=a[i+2];
//			cout<<"c";
//			cout<<a[i+2];
			x3+=1;
			continue;
			}
		}else{
			if(x1+1<=n/2){
				sum+=a[i];
//				cout<<"a"<<endl;
				x1+=1;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}

/*
1 4
4 2 1
3 2 4
5 3 4
3 5 1
*/

//Ren5Jie4Di4Ling5%
