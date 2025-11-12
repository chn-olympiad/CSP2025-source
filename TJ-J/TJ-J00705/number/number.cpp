#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char c[1000006]={};
	int a[10]={};
	cin>>c;
	for(int i=0;i<1000006;i++){
	  if(c[i]<='9'&&c[i]>='0') a[c[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++){
		    	cout<<i;
		    }
		}
    }
	return 0;
	
}
