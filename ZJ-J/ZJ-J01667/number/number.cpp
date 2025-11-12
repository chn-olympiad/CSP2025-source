#include<bits/stdc++.h>
using namespace std;
int r[1000005],cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			r[++cnt]=a[i]-48;
		}
	}
	sort(r+1,r+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<r[i];
	}
	return 0;
}