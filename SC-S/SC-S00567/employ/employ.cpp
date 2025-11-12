#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
int c[510],a[510];
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	fre("employ");
	int n,m,ans=0;
	string s;
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		a[i]=i;
	}
	do{
		int cntl=0,cnta=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||cntl>=c[a[i]]){
				cntl++;
				if(cntl>n-m){
					break;
				}
			}
			else{
				cnta++;
				if(cnta>=m){
					ans++;
					break;
				}
			}
		}
	}while(next_permutation(a+1,a+1+n));
	cout<<ans;
}