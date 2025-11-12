#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[1000][3],x,y,z,num,sum,b[1000];
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][0]>a[i][1]){
			if(a[i][0]>a[i][2]){
				x++;
				b[i]=a[i][0];}
			else{
				z++;
				b[i]=a[i][2];}
		}
		else if(a[i][1]>a[i][2]){
			y++;
			b[i]=a[i][1];}
			else{
				z++;
				b[i]=a[i][2];}
			sum=sum+b[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
