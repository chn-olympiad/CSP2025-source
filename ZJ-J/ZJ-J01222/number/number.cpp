#include<bits/stdc++.h>
using namespace std;
string a;
int n[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	int len = a.size();
	for(int i = 0;i<len;i++){
		if(int(a[i])<=57&&int(a[i])>=48){
			n[int(a[i])-48]++;	
		}
	}
	for(int i=9;i>=0;i--){
		while(n[i]>0){
			n[i]--;
			cout<<i;
		}
	}
	
	return 0;
}
