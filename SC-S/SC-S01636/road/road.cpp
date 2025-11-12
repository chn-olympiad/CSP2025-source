#include<iostream>
using namespace std;
int main(){
	int n,m,k,t,num=0;
	cin>>n>>m>>k;
	int a,b,c,q[1005];
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		q[i]=c;
	}
	for(int j=1;j<=k;j++){
		cin>>a;
		q[m+j]=a;
	    for(int i=1;i<=m;i++){
		    cin>>t;
		    q[m+i*j+j]=t;
	    }
    }
	for(int i=1;i<=(2*m+k-1)*(2*m+k-1);i++){
		if(q[i]>q[i+1]){
			int p=q[i];
			q[i]=q[i+1];
			q[i+1]=p;
		}
	}
	for(int i=1;i<=n;i++){
		num+=q[i];
	}
	cout<<num;
	return 0;
} 