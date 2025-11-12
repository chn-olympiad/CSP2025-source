#include<bits/stdc++.h>
using namespace std;
string a;
int number[1000006],c;
int main(){
	freopen("number.in","r",stdin);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			number[c]=a[i]-'0';
			c++;
		}
	}
	sort(number,number+c);
	freopen("number.out","w",stdout);
	for(int i=c-1;i>=0;i--){
		cout<<number[i];
	}
	//cout<<number[0]<<" "<<number[1]<<" "<<number[2];
	
	return 0;
}
