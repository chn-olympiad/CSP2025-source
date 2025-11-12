#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500009]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i]^a[i-1];
	}
	int b[1100000]={0};
    int r=0,g=0;
    for(int i=0;i<1100000;i++){
        b[i]=-1;
	}
    b[0]=0;
    for(int i=1;i<=n;i++){
    	if(r<=b[a[i]^k]){
    		r=i;
    		g++;
		}
		b[a[i]]=i;
	}
	cout<<g;
	return 0;
}
