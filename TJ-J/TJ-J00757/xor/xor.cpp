#include <bits/stdc++.h>
using namespace std;
#define int long long
bool fl=true;
int ara[500005];//离谱 
int fra[500005];//先帝创业未半而中道崩殂，今天下三分，益州疲敝，此诚危急存亡之秋也......臣本布衣，躬耕于南阳，苟全性命于乱世，不求闻达于诸侯，先帝，不以臣卑鄙 ，为此往屈，资臣以当世之势...... 
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int nn,ks,anss=0;
	cin>>nn>>ks;
	for(int i=1; i<=nn; i++) {
		cin>>ara[i];
		if(i==1) {
			fra[0]=fra[i]=ara[i];
			continue;
		}
		if(ara[i]!=ara[1]){
			fl=false;
		}
		fra[i]=fra[i-1]^ara[i];
	}
	if(fl){
		if(ks==0){
			cout<<nn/2;
		}else if(ks==ara[1]){
			cout<<nn;
		}else{
			cout<<0;
		}
		return 0;
	} 
	for(int i=1; i<=nn; i++) {
		for(int j=i; j<=nn; j++) {
			if(i==j) {
				if((fra[j]|fra[i])==ks) {
					i=j;
					anss++;
					break;
				}

			} else if((fra[j]|fra[i-1])==ks) {
				i=j;
				anss++;
				break;
			}
		}
	}
	cout<<anss;
	return 0;
}//the exam is very very good,I hope that the teacher who wrote the text can be very healthy and everything follows your mind.I hope to get 100 in this text. 
