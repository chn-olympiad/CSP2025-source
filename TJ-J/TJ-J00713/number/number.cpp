#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	short n[a.length()];
	int idx1 = 0;
	for(int i = 0;i < a.length();i++){
		if(a[i] >= '0'&&a[i] <= '9'){
			n[idx1] = a[i]-'0';
			idx1++;
		}
	}
    sort(n,n+idx1);
	for(int i = idx1-1;i >= 0;i--){
		cout<<n[i];
    }
    //我真有实力!
	return 0;
}
