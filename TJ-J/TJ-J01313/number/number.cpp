#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int sl[15]={};
	string a;cin>>a;
	int b=a.size();
	for(int i=0;i<b;i++){
		if(a[i]-48<=9){
			sl[a[i]-48]++;
		}
	}for(int i=9;i>=0;i--){
//		cout<<sl[i]<<"\n";
		for(int j=0;j<sl[i];j++) cout<<i;
	}
	return 0;
}
