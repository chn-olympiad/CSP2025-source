#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("r","saet.in",stdin);
	freopen("w","seat.out",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int c=a[0],d=0;
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m-i;j++){
			if(a[j]<a[j+1]){
				int b=a[j+1];
				a[j+1]=a[j];
				a[j] = b;
			}
		}
	}
	for(int i=0;i<n*m;i++){
	    //cout<<a[i]<<endl;
		if(a[i]==c){
			d=i+1;
			//cout<<d;
		}
	}
	int h=0,l=0;
	if(d%n>0){
	l=d/n+1;
	}
	else{
		l=d/n;
	}
	if(d==1){
		h=1;
	}
	else if(d%n==0)
	{
		//cout<<"1";
		h=n;
	}
	else if(l%2==0){
		//cout<<"2";
		h=d%n;
		h--;
		h=n-h;
	}
	else{
		//cout<<"3";
		h=d%n;
	}
	cout<<l<<" "<<h;
		return 0;
	fclose(stdin);
	fclose(stdout);
}
