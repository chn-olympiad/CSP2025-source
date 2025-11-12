#include <bits/stdc++.h>
using namespace std;
int sn[1005];
string n;
int cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int l;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			sn[i]=int (n[i]-'0');
			cnt++;
		}
	}sort(sn+0,sn+cnt+1);
		for(int i=cnt;i>=cnt;i--){
			cout<<sn[i];
		}
		for(int i=cnt;i--;){
			cout<<sn[i];
		}
	return 0;
}


