#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int a[n.size()];
	int h=0;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0' && n[i]<='9'){
			a[h]=n[i]-'0';
			h++;
		}
	}
	if(h==n.size()){
		cout<<n;
		return 0;
	}
	sort(a,a+h);
	for(int i=h-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
