#include<bits/stdc++.h>
using namespace std;
int n,a[10000],p=0;
void d(int s,int f,int j,int c){//s:总大小，f：位置；j：最大 c:层 
	if(c==1){
		for(int i=f-1;i>=c;i--){
			if(j*2<s+a[i])p++;
			else break;
	}return;
	}
	for(int i=f-1;i>=c;i--){
		d(s+a[i],i,max(j,a[i]),c-1);
	}
}
int main(){
    freopen("polygon4.in","r",stdin);
    freopen("polygon.out","w",stdout);
    
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}sort(a+1,a+1+n) ;
	for(int i=3;i<=n;i++){
		d(0,n+1,0,i);
	}cout<<p;
    return 0;
}/*5
1 2 3 4 5*/

