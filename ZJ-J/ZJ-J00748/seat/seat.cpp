#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n;
	cin>>m;
	int c=n*m;
	
	int a[c]={0};
	
	for(int i=0;i<c;i++){
		cin>>a[i];
	}
	int aone;
	aone=a[0];
	sort(a,a+c);
	int f=0;
	for(int i=0;i<c;i++){
		if(a[i]==aone){
			f=i+1;
			
		}
	}
	f=c+1-f;
    
    int an,am;
    an=(f-1)/m+1;
    if(an%2!=0){
    	am=f%m;
	}
	else{
		am=m-f%m+1;
	}
	cout<<an<<' '<<am;
    
	return 0;
}
