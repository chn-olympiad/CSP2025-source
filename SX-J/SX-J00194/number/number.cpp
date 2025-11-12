#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;cin>>n;
	int a[13]={0};
	int l=n.size();
	for(int i=0;i<l;i++){
		if(n[i]>='0'&&n[i]<='9')a[n[i]-'0']++;
	}
	for(int i=9;i>=1;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	for(int i=1;i<=a[0];i++)cout<<"0";




	return 0;
}