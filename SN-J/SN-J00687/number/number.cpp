#include<bits/stdc++.h>
using namespace std;
int a[1077];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int o=1;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[o]=s[i]-'0';
			o++;
		}
	}
	o-=1;
	int n;
	for(int i=1;i<=o;i++){
		for(int j=1;j<=o;j++){
			if(j!=o){
				if(a[j]>a[j+1]){
		    		n=a[j];
		    		a[j]=a[j+1];
		    		a[j+1]=n;
				}
			}
		    
	    }
	}
	for(int i=o;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
