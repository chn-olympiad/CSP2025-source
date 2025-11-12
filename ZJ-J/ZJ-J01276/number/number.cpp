#include<bits/stdc++.h>
using namespace std;
string a;
int lenb;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>a;
	int b[a.size()+5];
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			//cout<<a[i]<<endl;
			b[lenb]=a[i]-'0';
			lenb++;
		}
	}
	sort(b,b+lenb);
	for(int i=lenb-1;i>=0;i--){
		if(b[lenb-1]==0){
			cout<<0;
			return 0;
		}
		cout<<b[i];
	}
	return 0;
}
