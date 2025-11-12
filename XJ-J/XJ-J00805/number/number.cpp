#include <bits/stdc++.h>
using namespace std;
string m;
long long a[50]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>m;
    long long n=m.size();
    for(int i=0;i<n;i++){
    	if(m[i]>='0' && m[i]<='9'){
    		int h=m[i]-'0';
    		a[h]++;
		}
	}
	for(int i=10;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
