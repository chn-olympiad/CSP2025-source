#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int z=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[z]=s[i];
			z++;
		}
	}
		for(int x=0;x<z;x++){
			for(int j=x+1;j<z;j++){
				if(a[x]<a[j]){
					int t=a[x];
					a[x]=a[j];
					a[j]=t;
				}
		}
		}
	for(int i=0;i<z;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
