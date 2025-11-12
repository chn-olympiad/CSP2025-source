//陈祥 SN-S00751 陕西省丹凤中学
#include<bits/stdc++.h>
using namespace std;
int arr[10003][4];
vector<int> dp(1e5+3,0);
int big(int a,int b,int c){
	if(a>=b&&a>=c) {int i=1;return i;}
	if(b>=a&&b>=c) {int i=2;return i;}
	if(c>=a&&c>=b) {int i=3;return i;}
	return 0;
}

int middle(int a,int b,int c){
	if(a>=b&&a>=c&&b>=c) return 2;
	if(a>=b&&a>=c&&c>=b) return 3;
	if(b>=a&&b>=c&&a>=c) {return 1;}  else{return 3;}
	if(c>=a&&c>=b&&a>=b) {return 1;}  else{return 2;}
	return 0;
}
int m1(int a,int b,int c) {if(a<=b&&a<=c) {int i=1;return i;}
	if(b<=a&&b<=c) {int i=2;return i;}
	if(c<=a&&c<=b) {int i=3;return i;}
}
int m2(int a,int b){
	return a>=b?2:1;
}
int m3(int a,int b){
	return a>=b?3:1;
}
int m4(int a,int b){
	return a>=b?3:2;
}
int club(int i){
	int num[4]={0,0,0,0}; //save the number of each club;
	int ans=0;
	for(int j=1;j<=i;j++){
		if(arr[j][1]==arr[j][2]&&arr[j][3]==arr[j][2]) {if(num[m1(arr[j][1],arr[j][2],arr[j][3])]<=i/2){num[m1(num[1],num[2],num[3])]++; 
		ans+=arr[j][big(arr[j][1],arr[j][2],arr[j][3])];}}
		if(arr[j][1]==arr[j][2]&&arr[j][3]<arr[j][2]) {num[m2(num[1],num[2])]++; 
		ans+=arr[j][m2(num[1],num[2])];}
		if(arr[j][1]==arr[j][3]&&arr[j][3]>arr[j][2]) {num[m3(num[1],num[3])]++; 
		ans+=arr[j][m3(num[1],num[3])];}
		if(arr[j][3]==arr[j][2]&&arr[j][1]<arr[j][2]) {num[m4(num[2],num[3])]++; 
		ans+=arr[j][m4(num[2],num[3])];} else{if(num[big(arr[j][1],arr[j][2],arr[j][3])]<=i/2) {num[big(arr[j][1],arr[j][2],arr[j][3])]++; 
		ans+=arr[j][big(arr[j][1],arr[j][2],arr[j][3])];}
		else {num[middle(arr[j][1],arr[j][2],arr[j][3])]++;
		ans+=arr[j][middle(arr[j][1],arr[j][2],arr[j][3])];}
		}
		
	}
	return ans;
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	for(int i=1;i<=t;i++){
		int n; cin>>n;
		for(int j=1;j<=n;j++){
			int a,b,c;
			cin>>a>>b>>c;
			arr[j][1]=a; arr[j][2]=b; arr[j][3]=c;
		}
		cout<<club(n)<<endl;
	}
	return 0;
}
