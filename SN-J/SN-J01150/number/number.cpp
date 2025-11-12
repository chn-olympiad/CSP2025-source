#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	/*char a[100];
	for(long long i=1;true){
		cin>>a[i];
	}*/
	long long a[1000],b,max,x;
	for(long long i=1;i<=2;i++){
		cin>>a[i];
		b++;
	}
	for(long long i=1;i<=b;i++){
		max=0;
		for(long long j=i;j<=b;j++){
		    if(a[j]>max){
		    	max=a[j];
		    	x=j;
			}
	    }
	    swap(a[i],a[x]);
	}
	for(long long i=1;i<=b;i++){
		cout<<a[i];
	}
	return 0;
}
