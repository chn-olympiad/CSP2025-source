#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int l=a.size(),t[11]={};
	for(int i=0;i<l;i++){
		if(a[i]>='0' and a[i]<='9'){
			t[a[i]-48]++;
		}
	}for(int i=9;i>=0;i--){
		if(t[i]){
			for(int j=1;j<=t[i];j++)cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
