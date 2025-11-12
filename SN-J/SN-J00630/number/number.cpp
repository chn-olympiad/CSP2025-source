#include<bits/stdc++.h>
using namespace std;
string s;
int a[15],cs;
int main(){
	//freopen("number4.in","r",stdin);
	//freopen("number4.out","w",stdout);
    cin>>s;
    int t=s.size();
    for(int i=0;i<t;i++){
    	int b=s[i]-48;
    	if(b>=0 &&b<=9){
    		a[b]++;
    		cs++;
		}
	}
	int idx=9;
	while(cs>0){
		if(a[idx]==0){
			idx--;
		}else{
			cout<<idx;
			a[idx]--;
			cs--;
		}
	}
	return 0;
}
