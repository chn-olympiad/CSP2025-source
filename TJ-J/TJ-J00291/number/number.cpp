#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int k[100086];
	cin>>a;
	for(int i=0;i<a.size() ;i++){
		if(a[i]<='9'&&a[i]>='0'){
			k[i]=a[i]-'0';
		}else{
			k[i]=-1;
		}
	}

	sort(k,k+a.size());
	for(int i=a.size();i>0;i--){
		if(k[i-1]>=0){
			cout<<k[i-1];
		}
	}
	return 0;
}
