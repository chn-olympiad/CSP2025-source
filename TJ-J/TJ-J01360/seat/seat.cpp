#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdout); 
	freopen("seat.out","w",stdin);
	//n是里
	//m是和 
	int n;
	int m;
	int a[10000];
	int b[10000];
	int r=0;
	int q=0;
	int h;
	int l;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
			cin>>a[i];
			r++;
	} 

	int d=a[0];
	for(int j=1;j<r;j++){
		if(d<a[j]){
			//q是比我高的ren 
			q++;	
		}		
	}

	h=q%m+1;
	l=q/n+1;
	if(l%2==0){
		h=m-h;
	}
		
		cout<<l<<h<<endl;
	return 0;
} 
