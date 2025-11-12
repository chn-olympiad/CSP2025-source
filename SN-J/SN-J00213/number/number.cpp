//周琪明 SN-J00213 西安滨河学校 
#include<bits/stdc++.h>
#define ll long long
#define str string
using namespace std;
str zh_s;
ll zh_zc[1000000],zh_zcsize=0,zh_da=0;
int zh_a;
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	cin>>zh_s;
	for(ll i=0;i<zh_s.size();i++){
		if(zh_s[i]<='9'&&zh_s[i]>='0'){
			zh_zc[zh_zcsize]=zh_s[i]-'0';
			zh_zcsize++;
		}
	}
	for(ll i=zh_zcsize;i>=0;i--){
		for(ll j=0;j<=i;j++){
			if(zh_zc[j]<zh_zc[j-1]){
				zh_a=zh_zc[j];
				zh_zc[j]=zh_zc[j-1];
				zh_zc[j-1]=zh_a;
			}
		}
	}
	for(ll i=zh_zcsize;i>=0;i--){
		zh_da*=10;
		zh_da+=zh_zc[i];
	}
    printf("%lld",zh_da);
	return 0;
}
