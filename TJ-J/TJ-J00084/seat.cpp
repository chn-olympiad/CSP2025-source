#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,y,h,a;
	long long arr[300],s[300][300];
	int sum=0,f=0;
	cin>>n>>m;
	for(int i=1;i<=f;i++){
		while(cin>>p){
	if(p=' '){
		arr[f]=sum;
		sum=0;f++;
	}sum=sum*10+p;
	}
	}
	for(int i=1;i<=f;i++){
	if(arr[i]<arr[i+1]||a<arr[i]){
		 a=arr[i];
	}else{
		 a=arr[i+1];
	}}
for(int j=1,y=1;j<=f;j++){
	for(int u=f,h=f;j>=1;u--){
	if(f=j*m){
		if(j>y&&u<h){
			y=j;
			h=u;
		}}}
}
	for(int i=1;i<=y;i++){
		for(int l=1;l<=h;l++){
		if(l%2==1){
			s[i][l]=arr[i*l];
		}	else{
			s[i][l]=arr[(y-i)*l];
		}
		}
	}
	int tmp=a%y,uto=a/tmp;
	cout<<uto<<tmp;

}
