#include <bits/stdc++.h>
using namespace std;
int mian(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000],n;
	for (int i=0;i<s.length();i++){
		if(0<=s[i]<=9){
			a[s[i]]++;
			n++;
		}
	}
	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
		    if(a[i]<a[j+1]){
		    	int t=a[i];
		    	a[i]=a[j+1];
		    	a[j+1]=t;
	    	}
    	}
	}
	for(int i=0;i<n;i++){
	    cout<<a[i];
    }
    return 0;
	
}
