#include<bits/stdc++.h>
using namespace std;
string a;
int num[10005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<=len-1;i++){
		if(48<=a[i]&&a[i]<=57) num[a[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
