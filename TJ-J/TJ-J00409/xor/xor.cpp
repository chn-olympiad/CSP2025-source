#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int b[1000006];
int c[1000006];
int f(int n){
	int i = 0;
	b[1] = 0;
	c[1] = 0;
	while(n!=0){
	    b[i] = n%2;
	    n = n/2;
	    i++;
	}
	int a = i;
	for(int j = 1;j<=a;j++){
		c[j] = b[i];
		i--;
	}
	return a;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	long long k;
	cin>>k;
	bool m = 0;
	if(k == 0){
		m = 1;
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i] == 1){
			m = false;
		}
	}
	if(m){
		cout<<n/2;
		return 0;
	}
	int p = 0;
	if(k == 1){
		p = 0;
	    for(int i = 1;i<=n;i++){
	    	if(a[i] == 1){
		    	p++;
	    	}
    	}
    	cout<<p;
    	return 0;
	}
	if(k == 0){
		p = 0;
		for(int i = 1;i<=n;i++){
	    	if(a[i] == 0){
		    	p++;
	    	}
    	}
    	for(int i = 1;i<n;i++){
	    	if(a[i] == 1 && a[i+1] == 1){
	    		i++;
		    	p++;
	    	}
    	}
    	cout<<p;
    	return 0;
	}
}

