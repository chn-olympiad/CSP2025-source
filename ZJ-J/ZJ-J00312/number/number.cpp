#include<bits/stdc++.h>
using namespace std;
string a;
int b[15];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int t=a.size();
	for(int i=0;i<t;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[(int)a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]>0){
			cout<<i;
			b[i]--;
		}
	}
	return 0;
}
