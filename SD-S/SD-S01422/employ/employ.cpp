#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=20;
const int M=998244353;
int n,m,a[N],c[N],l;
bool b[N];
string s;
void dbs(int st){
	if(st==n+1){
		int p=0,q=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				q++;
			}else{
				if(q>=a[c[i]]){
					q++;
				}else{
					p++;
				}
			}
		}
		if(p>=m){
			l++;
//			for(int i=1;i<=n;i++){
//				cout<<c[i]<<" "; 
//			}
//			cout<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			c[st]=i;
			b[i]=1;
			dbs(st+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s=" "+s;
	dbs(1);
	cout<<l%M;
	return 0;
}
