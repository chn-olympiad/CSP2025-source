#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010],c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	if(a.length()==1&&a[0]>='0'&&a[0]<='9'){
		cout<<a[0]<<endl;
		return 0;
	}
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[c]=int(a[i])-48;
			c++;
		}
	}
	sort(b,b+c);
	for(int i=c-1;i>=0;i--){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
