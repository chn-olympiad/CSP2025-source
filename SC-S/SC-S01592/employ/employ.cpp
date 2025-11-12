#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int ru[10005],ren,yon;
string t;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>ren>>yon>>t;
	for(int i=1;i<=ren;i++) cin>>ru[i];
	int aa=1,bb=1;
	if(yon==1){
		cout<<ren;
		return 0;
	}
	for(int i=1;i<=ren;i++){
		aa%=mod;
		aa*=i;
	}
	for(int i=1;i<=yon;i++){
		bb%=mod;
		bb*=i;
	}
	cout<<aa/bb;
	fclose(stdin);
	fclose(stdout);
	return 0;
}