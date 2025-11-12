#include<bits/stdc++.h>
using namespace std;
string a;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	const int sz=a.size();
	for(int i=0;i<sz;i++){
		if(a[i]>='0'&&a[i]<='9'){
			cnt[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<cnt[i];j++){
			cout<<char(i+'0');
		}
	}
	fclose(stdin); 
	fclose(stdout); 
	return 0;
}
