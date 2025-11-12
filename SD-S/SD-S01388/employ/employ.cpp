#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long C[100100],S[100100];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.in","w",stdout);
	long long n,m,i,ans,mo = 998244353;
	cin>>n>>m;
	for(i = 1;i <= n;i++){
		cin>>C[i];
	}
	sort(C+1,C+1+n);
	for(i = 1;i <= n;i++){
		cin>>S[i];
	}
	if(m == 1){
		ans = 1;
		for(i = 1;i <= n;i++){
			ans *= i;
			ans *= mo;
		}
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//12pts
