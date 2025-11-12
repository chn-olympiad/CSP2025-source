#include<bits/stdc++.h>
using namespace std;
char c[1000100];
int a[1000100],ans,s;
int lc;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c+1;
	lc=strlen(c+1);
	for(int i=1;i<=lc;i++){
		if(c[i]>='0'&&c[i]<='9'){
			a[++s]=c[i]-'0';
		}
	}
	sort(a+1,a+s+1);
	for(int i=s;i>=1;i--) cout<<a[i];
	return 0;
}
