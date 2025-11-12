#include<bits/stdc++.h>
using namespace std;
string zfc,sz;
int main(){
	cin>>zfc;
	int cd=zfc.size();
	for(int i=0;i<=cd-1;i++){
		if(zfc[i]>='0'&&zfc[i]<='9'){
		sz+=zfc[i];	
		}
	}
	int cd2=sz.size();
	int cd3=cd2;
	while(cd3--){
		for(int i=0;i<=cd2-1;i++){
		if(sz[i]<sz[i+1]){
			swap(sz[i],sz[i+1]);
		    }
    	}
	}
	for(int i=0;i<=cd2-1;i++){
		cout<<sz[i];
	}
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	return 0;
}

