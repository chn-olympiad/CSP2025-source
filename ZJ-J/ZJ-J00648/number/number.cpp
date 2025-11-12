#include<bits/stdc++.h>
using namespace std;
int t[15],n;
string a;
int main(){
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			t[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]!=0){
			cout<<i;
			t[i]--;
		}
	}

	return 0;
}

