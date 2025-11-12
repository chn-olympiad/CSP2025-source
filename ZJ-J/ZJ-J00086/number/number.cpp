#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	string s;
	cin>>s;
	int j=-1;
	int b=-1;
	for (int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			j++;
			a[j]=s[i]-48;
			b++;
		}
	}
	int maxx=0;
	for (int k=9;k>=0;k--){
		for (int j=0;j<=b;j++){
			if (a[j]==k){
				cout<<k;
			}
		}
	}
	return 0;
}
