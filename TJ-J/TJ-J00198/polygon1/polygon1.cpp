#include <bits/stdc++.h>
using namespace std;
void search(int gs){
	int c[gs];
	int a=0;
	int max=0;
	for(int i=0;i<=gs;i++){
		cin>>c[i];
		a+=c[i];
		if(c[i]>max) max=c[i];
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int c[n];
	int a=0;
	int max=0;
	for(int i=0;i<=gs;i++){
		cin>>c[i];
		a+=c[i];
	}
	cout<<c[1]+c[2]<<endl;
}
