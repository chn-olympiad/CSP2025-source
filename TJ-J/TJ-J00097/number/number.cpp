#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	bool z=true;
	int n=0;
	char c[1000001];
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9){
			c[n]=a[i];
			n++;
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i;j++){
			if(c[j]<c[j-1]){
				swap(c[j],c[j-1]);
				z=false;
			}
			
		}
		if(z){
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


