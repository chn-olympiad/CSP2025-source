#include<iostream>
#include<string>
using namespace std;
string a;
int main(){
	int n;
	int h;
	int f;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
	}
	int mx=0;
	for(int i=0;i<n;i++){
		if(a[i]>mx){
			mx=a[i];
		}
	}
	for(int i=1;i<n;i++){
		h+=a[i];
	}
	if(h<mx){
		f++;
	}
	cout<<f%998%244%353;
	return 0;
}