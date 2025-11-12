#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long s[150];
	cin>>a;
	int a1=a.size();
	for(int i=1;i<=a1;i++){
		if(a[i]>='1' && a[i]<='9'){
			for(int j=1;j<=9;j++){
				if(a[i]==j){
					s[j]=a[i];
				}
			}
		}
	}
	for(int i=9;i>=1;i--){
		for(int j=1;j<=9;j++){
			int b=max(s[j-1],s[j]);
			cout<<b;
			return 0;
		}
	}
	 
	return 0;
}
