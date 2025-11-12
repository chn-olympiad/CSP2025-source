#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+23;
string sn;
int c = 1; 
int v[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int gg = -1;
	cin>>sn;
	for(int i=0;i<sn.size();i++){
		
		if(int(sn[i])-48 < 10 && int(sn[i])-48>=0){
			v[c] = int(sn[i])-48;
			c++;
		} 
		 
	}
	sort(v+1,v+c);
	for(int i=c-1;i>=1;i--){
		cout<<v[i];
	}	
	return 0;
}

