#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string si;
	cin>>si;
	int chang=si.size(),su=0;
	int shu[chang];
	for(int i=0;i<chang;i++){
		if(si[i]>='0'&&si[i]<='9'){
			shu[su]=si[i]-'0';
			su++;
		}
	}sort(shu,shu+su);
	for(int i=su-1;i>=0;i--){
		cout<<shu[i];
	}
	return 0;
}