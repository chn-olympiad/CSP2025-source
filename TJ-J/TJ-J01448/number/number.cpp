#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string b;
	cin>>b;
	int k=0,j=0;
	for (int i=0;i<=b.size();i++){
		if (b[i]>='0' && b[i]<='9'){
			a[j]=b[i]-'0';
			k++;
			j++;
	    }
	}
	sort(a,a+k);
	for (int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
