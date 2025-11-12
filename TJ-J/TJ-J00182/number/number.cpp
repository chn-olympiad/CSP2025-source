#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int e=1;
	int n=a.size();
	int b[100001]={0};
	for(int i=0;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[e]=a[i]-48;
			e++;
		}
	}
	sort(b+1,b+e+1);
	for(int i=e;i>=2;i--){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
