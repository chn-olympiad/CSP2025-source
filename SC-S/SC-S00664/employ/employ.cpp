#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int n,m;
string s;
int c[maxn];
bool flag=0;
int jc(int x){
	int v=1;
	for(int i=1;i<=x;i++){
		v*=i;
	}
	return v;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
		cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]!='1'){
			flag=1;
			break;
		}
	}
	if(n==m){
		if(flag){
			cout<<0;
			return 0;
		}else{
			cout<<jc(n);
			return 0;
		}
	}
	if(!flag){
		cout<<jc(n);
		return 0;
	}
	return 0;
}