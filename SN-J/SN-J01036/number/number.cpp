#include<bits/stdc++.h>
using namespace std;
string c;
string n;
string r;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	char m;
	for(int i=0;i<c.length();i++){
		if(c[i]<='9'&&c[i]>='0'){
			n+=c[i];
		}
	}
	for(int i=0;i<n.length();i++){
		for(int j=i;j<n.length();j++){
			if(n[j]>n[i]){
				m=n[i];
				n[i]=n[j];
				n[j]=m;
			}
		}
	}
	cout<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
