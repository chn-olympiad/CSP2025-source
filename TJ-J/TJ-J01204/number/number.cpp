#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int main(){
	freopen("number.in","r",std.in);
	freopen("number.out","w",std.out);
	cin>>s;
	int n=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			a[n]=s[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}
