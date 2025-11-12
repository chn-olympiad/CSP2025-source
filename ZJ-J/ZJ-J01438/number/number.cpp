#include<bits/stdc++.h>
using namespace std;
char c[1000100];
int a[1000100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c+1;
	int n=0;
	int len=strlen(c+1);
	for(int i=1;i<=len;i++){
	    if(c[i]>='0'&&c[i]<='9'){
	    	a[++n]=c[i]-'0';
		}
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(int i=1;i<=n;i++)cout<<a[i];
	return 0;
}