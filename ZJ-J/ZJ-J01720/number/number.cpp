#include<bits/stdc++.h>
using namespace std;
char a[2000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=0;
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0' and n[i]<='9'){
			j++;
			a[j]=n[i];
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--){
		cout<<a[i];
	}
	cout<<'\n';
	return 0;
}
