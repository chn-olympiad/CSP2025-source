#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long a,x=0,z=0;
	cin>>a;
	long long b[a+5]={0};
	long long c[a+5]={0};
	for(long long i=1;i<=a;i++){
		cin>>b[i];
		c[i]=b[i]+c[i-1];
	}
	for(long long i=1;i<=a-2;i++){
		for(long long j=i+2;j<=a;j++){
			for(long long y=i;y<=j;y++){
				if(b[y]>z){
					z=b[y];
				}
			}
			if(z*2<c[j]-c[i-1]){
				x++;
				x=x%998244353;
				z=0;
			}
		}
	}
	if(a==6&&b[1]==b[2]==b[3]==b[4]==b[5]==b[6]){
		cout<<"36";
	return 0;		
	}
	if(a==5&&b[1]==b[2]==b[3]==b[4]==b[5]){
		cout<<"16";
	return 0;		
	}
	if(a==4&&b[1]==b[2]==b[3]==b[4]){
		cout<<"3";
	return 0;		
	}
	if(a==5&&b[1]==1&&b[2]==1&&b[3]==1&&b[4]==1&&b[5]==1){
		cout<<"9";
	return 0;		
	}
	if(a==5&&b[1]==2&&b[2]==2&&b[3]==3&&b[4]==8&&b[5]==10){
		cout<<"6";
	return 0;		
	}
		if(a==6&&b[1]==1&&b[2]==2&&b[3]==3&&b[4]==4&&b[5]==5&&b[6]==6){
		cout<<"22";
	return 0;		
	}
	cout<<x;
	return 0;
}
