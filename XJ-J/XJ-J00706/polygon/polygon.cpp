#include<iostream>
using namespace std;
int a[101];
int main(){
	/*freopen("s","r",stdin);
	freopen("s","r",stdin);*/
	int n,h=0,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=0;
		x=a[i]+a[i+1]+a[i+2];
		if(a[i]>m){
			m=a[i];}
		if(a[i+1]>m){
			m=a[i+1];}
		if(a[i+2]>m){
			m=a[i+2];}
		if(x>m*2){
			h++;
		}
	}
	cout<<h;
	/*fclose(stdout);
	fclose(stdout);*/
}
