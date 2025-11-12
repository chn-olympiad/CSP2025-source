#include <bits/stdc++.h>
using namespace std;
string str;
long long a[1005],f[1005],n1;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<=str.size();i++){
		if(str[i]>='0' && str[i]<='9'){
			if(f[(str[i]-'0')]==0){
				a[++n1]=(str[i]-'0');
				f[(str[i]-'0')]=1;
			}
		}
	}
	sort(a+1,a+1+n1,cmp);
	long long ans=0;
	for(int i=1;i<=n1;i++){
		ans=ans*10+a[i];
	}
	printf("%lld",ans);
	return 0;
}