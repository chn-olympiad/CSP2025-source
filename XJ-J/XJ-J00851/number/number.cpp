#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    int m=0;
    for(int i=0;i<n;i++){
    	if(int(s[i])-48<=9&&int(s[i])-48>=0){
    		a[m]=int(s[i])-48;
    		m++;
		}
	}
	sort(a+0,a+m);
    for(int i=m-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
