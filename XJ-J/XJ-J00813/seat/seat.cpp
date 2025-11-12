#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int b=0,c=0,c1=0,d=0,e=0,f=0;
	cin>>d>>f;
	cin>>a[0];
	c1=a[0];
	for(int i=1;i<d*f;i++){
		cin>>a[i];
	}
	for(int i=0;i<d*f;i++){
		for(int j=i+1;j<d*f;j++){
			if(a[i]<a[j]){
				e=a[i];
				a[i]=a[j];
				a[j]=e;
			//	cout<<a[i]<<' '<<a[j]<<' '<<e<<endl;
			}
		}
		if(a[i]==c1){
			c=i+1;
		}
	//	cout<<a[i]<<endl;
	}
	//cout<<c<<endl;
	if(c>d){
		if(c/d%2==0){
			if(c%d==0){
				cout<<c/d<<' '<<d;
			}
			else{
				cout<<c/d+1<<' '<<c%d;
			}
		}
		else{
			if(c%d==0){
				cout<<c/d<<' '<<1;
			}
			else{
				cout<<c/d+1<<' '<<d-c%d+1;
			}
		}
	}
	else{
		cout<<'1'<<' '<<c;
	}
	return 0;
} 
