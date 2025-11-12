#include<bits/stdc++.h>
using namespace std;
int  s;
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	
		if(s<'0'&&s>'9'){
			return 0;
		}
		if(s>=1&&s<=9){
			cout<<s;     
		}
		return 0;
}                      														
