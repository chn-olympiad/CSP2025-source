#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	if(x.length()==1){
		cout<<x;
		return 0;
	}
	int j=1;
	for(int i=0;i<x.length();i++){
		if((x[i]<='9')){
			a[j]=x[i]-'0';
			j++;
		}
	}
	j--;
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
