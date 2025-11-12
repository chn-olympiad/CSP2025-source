#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len1=a.size();
	int bi=1;
	for (int i=0;i<len1;i++){
		if (a[i]>='0' && a[i]<='9'){
			b[bi]=int(a[i])-48;
			bi++;
		}
	}
	sort(b+1,b+bi+1);
	for (int i=bi;i>1;i--){
		cout<<b[i];
	}
	return 0;
}
