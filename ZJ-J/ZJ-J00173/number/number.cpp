#include<bits/stdc++.h>
using namespace std;
string a;
int n;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int m=a.length();
	n=0;
	for(int i=0;i<m;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[n+1]=a[i]-'0';
			n++;
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[i]<b[j]){
				int x=b[i];
				b[i]=b[j];
				b[j]=x;
			}
		}
	}*/
	sort(b+1,b+n+1);
	if(b[n]==0){
		cout<<n;
		return 0;
	}
	for(int i=n;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}
