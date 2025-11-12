#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[100005],b[100005];
	for(int i=0;i<100005;i++){
		cin>>a[i];
		if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
			b[i]=a[i];
		}
	}
	for(int i=0;i<10005;i++){
		if(b[i]<b[i-1]){
			int t=b[i-1];
			b[i-1]=b[i];
			b[i]=t;
		}
		cout<<b[i];
	}
	return 0;
}
