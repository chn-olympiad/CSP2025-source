//SN-S00717 guohaoxuan xianguojigangwuqutieyizhongluganggaojizhongxue
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,q;
struct use{
	string yw;
	string fy;
}a[N];
map<string,string>b;
int th(string qe,string jg){
	int l,r,le = qe.size(),ret = 0;
	string zo = "",zj = "",yo = "";
	for(int i = 1;i <= le;i++){
		if(qe[i - 1] == jg[i - 1]){
			zo = zo + qe[i - 1];
		}
		else{
			l = i;
			break;
		}
	}
	for(int i = le;i >= 1;i--){
		if(qe[i - 1] == jg[i - 1]){
			yo = qe[i - 1] + yo;
		}
		else{
			r = i;
			break;
		}
	}
	for(int i = l;i <= r;i++){
		zj += qe[i - 1];
	}
	if(b[qe] == jg){
		ret += 1;
	}
	string qk1 = zo + zj,qk2 = zj + yo,qk3 = zo + b[zj] + yo;
	if(b[qk1] == jg){
		ret += 1; 
	}
	if(b[qk2] == jg){
		ret += 1;
	}
	if(qk3 == jg){
		ret += 1;
	}
	return ret;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> a[i].yw >> a[i].fy;
		b[a[i].yw] = a[i].fy;
	}
	for(int i = 1;i <= q;i++){
		string qe,jg;
		cin >> qe >> jg;
		if(qe.size() != jg.size()){
			cout << "0\n";
			continue;
		}
		cout << th(qe,jg) << "\n";
	}
	return 0;
}

