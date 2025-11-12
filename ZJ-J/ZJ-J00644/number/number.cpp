#include<bits/stdc++.h>
using namespace std;
int p[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0' && s[i]<='9'){
    		p[(s[i]-'0')]++;
		}
	}
	bool f=true;
	for(int pq=9;pq>=1;pq--){
	    for(int j=1;j<=p[pq];j++){
			cout<<pq;
		}
		if(p[pq]){
			f=false;
		}
	}
	if(f){
		cout<<0;
	}else{
		for(int j=1;j<=p[0];j++){
			cout<<0;
		}
	}
	return 0;
}