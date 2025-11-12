#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[10001],b[10001];
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
		}
		if(a[i]!=0){
			b[i]=a[i];
		}
	}
	sort(b,b+n);
	for(int i=n;i>=0;i--){
		if(b[i]!=0){
			cout<<b[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

