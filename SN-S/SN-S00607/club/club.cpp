//SN-J00607    芦思辰  高新第一学校 
#include<bits/stdc++.h>
using namespace std;
int main(){ 
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int n ,m,num=0,ans = 0,s1,s2,s3,a[5],b[5],c[5];
	cin >> n;
	if(n==2){
	for(int i=1;i<=2;i++){
		cin >> a[i] >> b[i];
	}		
	if(a[1]>b[1] && a[1]>a[2] && a[1]>a[3]){
			num = a[1];
			if(b[2]>b[3])    ans+=b[2];
			else  ans+=b[3]; 
		}
		 if(a[2]>b[2] &&  a[2]>a[1]>a[3]){
			num+=a[2];
			if(b[1]>b[3])    num+=b[1];
			else    num +=b[3];
		}
		else if(a[3]>b[3] && a[3]>a[2]>a[1]){
			num +=a[3];
			if(b[1]>b[2])  num+=b[1];
			else num+=b[2];
		}
	
	}
	cout <<num+ans+2 << endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
