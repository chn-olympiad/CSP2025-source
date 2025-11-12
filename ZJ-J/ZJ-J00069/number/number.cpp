#include<bits/stdc++.h>
using namespace std;
int s[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=0;
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			s[++j]=(int)(a[i]-'0');
		}
	}
	sort(s+1,s+1+j);
	for(int i=j;i>=1;i--){
		cout<<s[i];
	}
}
