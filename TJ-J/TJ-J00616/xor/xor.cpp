#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[10000][10000];
int gou(long long i,long long j){
	int s=a[i];
	for(long long k=i+1;k<=j;k++){
		s^=a[k];
	
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,num=0;
	cin>>n>>k;
    for(long long i=1;i<=n;i++){
    	cin>>a[i];
	}for(long long i=1;i<=n;i++){
		for(long long j=1;j<=i;j++){
		     b[i][j]=gou(j,i);
		     if(b[i][j]==k){
		     	num++;
			 }
	    }
	}cout<<num;
	
	return 0;
}
