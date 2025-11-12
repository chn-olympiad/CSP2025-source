#include<bits/stdc++.h>
using namespace std;
int n,m,tr;
string s;
int c[501];
long long jc(int x){
	long long val;
	for(int i=2;i<=x;i++){
		val*=i;
		if(val>998244353){
			val%=998244353;
		}
	}
	return val;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","rw",stdout);
	cin>>n>>m;
	tr=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			tr--;
		}
	}
	cout<<jc(tr);
	return 0;
} 
