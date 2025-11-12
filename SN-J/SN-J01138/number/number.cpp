#include<bits/stdc++.h>
using namespace std;
int a[100005],i;
string b;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(int j=0;j<b.size();j++){
		if(b[j]>=48&&b[j]<=57){
			i++;
			a[i]=b[j]-48;
		}	
	}
	sort(a+1,a+i+1,cmp);
	for(int j=1;j<=i;j++){
		cout<<a[j];
	}
	return 0;
}
