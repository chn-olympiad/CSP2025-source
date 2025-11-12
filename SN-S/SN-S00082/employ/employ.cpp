#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int n,m;
struct kx{
	int id;
	int c;
}a[600];
string s;
int cmp(kx x,kx y){
	return x.c<y.c;
}
int lev[1000];
queue<kx>r;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=m;i++){
		a[i].id=i;
		cin>>a[i].c;
	}
	int fl=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			fl=1;
			break;
		}
	}
	if(fl==0){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=0;i<s.size();i++){
		lev[i+1]=(s[i]-'0');
	}
	int cc=0;
	int nx=0;
	for(int i=1;i<=m;i++){
		if(lev[i]==0){
			nx++;
			continue;
		}
		else if(lev[i]==1&&a[i].c>=nx){
			cc++;
		}
	}
	int det=2;
	long long int ans=0;
	if(cc<m){
		cout<<0;
		return 0;
	}
	else{
		ans++;
		int cc1=cc;
		while(cc1){
			int cc1=0;
			r.push(a[det]);
			for(int i=1;i<=n;i++){
				if(i!=det)r.push(a[i]);
			}
			for(int i=1;i<=n;i++){
				a[i]=r.front();
				r.pop();
			}
			int nx1=0;
			for(int i=1;i<=m;i++){
				if(lev[i]==0){
					nx1++;
					continue;
				}
				else if(lev[i]==1&&a[i].c>=nx1){
					cc1++;
				}
			}
			if(cc1>m){
				ans++;
				continue;
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}
