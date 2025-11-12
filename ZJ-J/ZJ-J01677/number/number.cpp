#include<bits/stdc++.h>
using namespace std;
int l,s,i,j,v[15];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	l=a.size();
	for(i=0;i<l;i++){
		if(a[i]<='9'){
			v[a[i]-48]++;
			s++;
		}
	}
	if(v[0]==s){
		cout<<0;
	}
	else{
		for(i=9;i>=0;i--){
			for(j=0;j<v[i];j++){
				cout<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
