#include<bits/stdc++.h>
using namespace std;
int a[5002];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	cnt=0;
	int b[18];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	b[0]=a[0]+a[1]+a[2];
	b[1]=a[0]+a[1]+a[3];
	b[2]=a[0]+a[1]+a[4];
	b[3]=a[0]+a[2]+a[3];
	b[4]=a[0]+a[2]+a[4];
	b[5]=a[0]+a[3]+a[4];
	b[6]=a[1]+a[2]+a[3];
	b[7]=a[1]+a[2]+a[4];
	b[8]=a[1]+a[3]+a[4];
	b[9]=a[2]+a[3]+a[4];
	b[10]=a[0]+a[1]+a[2]+a[3];
	b[11]=a[0]+a[1]+a[2]+a[4];
	b[12]=a[0]+a[2]+a[3]+a[4];
	b[13]=a[1]+a[2]+a[3]+a[4];
	b[14]=a[0]+a[1]+a[2]+a[3]+a[4];
	b[15]=a[0]+a[1]+a[3]+a[4];
	for(int i=0;i<15;i++){
		if(i==0&&b[i]>2*a[2]){
			cnt++;
		}
		if(i==1||i==3||i==6||i==10){
			if(b[i]>2*a[3]){
				cnt++;
			}
		}
		if(i==2||i==4||i==5||i==7||i==8||i==9||i==11||i==12||i==13||i==14||i==15){
			if(b[i]>2*a[4]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	fclose(polygon.in);
	fclose(polygon.out);
	return 0;
} 
