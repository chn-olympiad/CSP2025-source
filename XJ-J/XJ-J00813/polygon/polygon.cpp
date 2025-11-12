#include<bits/stdc++.h>
using namespace std;
long long a[10000006];
int b[1000006];

int h(int v,int w){
	int c=0;
	for(int i=v;i<=w;i++){
		int p=a[w]-b[i];
		if(p>b[w]*2){
			c++;
		}
	}
	return c;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int c=0,d=0,e=0,f=0,g=0;
	cin>>d;
	for(int i=1;i<=d;i++){
		cin>>b[i];
		a[i]=a[i-1]+b[i];
	}
	for(int i=1;i<=d-2;i++){
		for(int j=3;j<=d;j++){
			c+=h(i,j);
		}
	}
	cout<<c/3*3;
	return 0;
} 
