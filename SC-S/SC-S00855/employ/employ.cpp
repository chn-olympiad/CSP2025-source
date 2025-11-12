#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
int n,m,c[505];
string str,fstr;
long long jie(int x){
	long long o=1;
	for(int i=2;i<=x;i++){
		o=(1LL*o*1LL*i)%mo;
	}
	return o;
}
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
	int p=0;
	cin>>str;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		fstr=fstr+"1";
		if(c[i]>0) p++;
	}
	if(str==fstr){
		cout<<1LL*jie(p);
	}else if(n==1){
		sort(c+1,c+n+1);
	}
	return 0;
} 