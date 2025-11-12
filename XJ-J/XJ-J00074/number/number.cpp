#include<bits/stdc++.h>
using namespace std;
long long a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=10;i++){
		a[i]=0;
	}
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') {
			int v=s[i]-('1'-1);
			a[v]+=1; 
		}
	}
	long long b=0;
	for(int i=9;i>=0;i--){
	    if(a[i]!=0){
			for(int w=a[i];w>0;w--){ 
			    b=b*10+i;
		    } 
		}
	
	}
	cout<<b;
	return 0;
} 
