#include<bits/stdc++.h>
using namespace std;
int a[1000050];
string e(int x){
	string y,y1;
	int b=0;
	while(x>=1){
		y[b]=x%2+'0';
		x/=2;
		b++;
	}
	for(int i=b-1;i>=0;i--){
		y1+=y[i];
	}
	return y1;
}
int v(string x){
	int y=0,y2=0;
	int b=x.size();
	for(int i=0;i<x.size();i++){
		int c=1;
		for(int j=1;j<b;j++){
			c*=10;
		}
		y=y+(x[i]-'0')*c;
		b--;
	}
	while(y>=10){
		y2+=y%10;
		y/=10;
		y*=2;
	}
	y2+=y;
	return y2;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	string c;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			sum+=1;
			a[i]=-1;
		}
	}
	cout<<sum<<endl;
//	for(int i=0;i<n;i++){
//		if(a[i]!=-1){
//			for(int j=i;j<n;j++){
//				if(a[j]==-1) break;
//				else{
//					for(int k=0;k<=max(e(a[i]).size(),e(a[i]).size());k++){
//						
//					}
//				}
//			}
//		}
//	}
	return 0;
}
