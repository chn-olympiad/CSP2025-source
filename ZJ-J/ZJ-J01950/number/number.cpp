#include<bits/stdc++.h>
using namespace std;
const int mxn=1e6+10;
int noi[mxn],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string ccf;
	cin>>ccf;
	for(int i=0;i<ccf.size();i++){
		if(ccf[i]<='9'&&ccf[i]>='0'){
			noi[++cnt]=ccf[i]-'0';
		}
	}
	sort(noi+1,noi+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<noi[i];
	}
	return 0;
}

