#include<bits/stdc++.h>
using namespace std;
bool s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,j,m[10000]={0};
	int ren=0;
	int o;
	int h;
	cin>>n>>j;
	char n1[n];
	cin>>n1;
	for(int i=1;i<=n;i++){
		cin>>o[m];
	}
	for(int i=1;i<=n;i++){
	    if(s[m]==0){
	    	s=false;
	    	cout<<0;
	    	h++;
		} 
		if(s[m]==1){
			s=true;
			ren++;
			cout<<ren;
		}
		if(o[m]<h){
			cout<<o;
		}
	}
	return 0;
}
