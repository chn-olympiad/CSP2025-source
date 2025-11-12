//SN-J00686  汤佳忆  西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e5+5;
int n,k,a[MAXN];
struct f {
	int l,r,yhh,dx,id;
} ss[100005],sss[100005];
bool cmp(f a,f b){
	return a.dx<b.dx;
}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt;
	for(int i=1; i<=n; i++) cin>>a[i];
	int js=1;
	/*
	if(k==0){
		cout<<n/2;
		return 0;
	}
	*/
	if(k==0){
		cout<<n;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		cnt=a[i];
		for(int j=i; j<=n; j++) {
			cnt^=a[j];
			if(cnt==k) {
				ss[js].yhh=cnt;
				ss[js].l=i;
				ss[js].r=j;
				ss[js].dx=j-i;
				ss[js].id=js;
				js++;
			}

		}
	}
	js--;
	/*
	cout<<"js="<<js<<"\n";
	for(int i=1;i<=js;i++){
		cout<<"l="<<ss[i].l<<" r="<<ss[i].r<<" yhh="<<ss[i].yhh<<" dx="<<ss[i].dx<<" id"<<ss[i].id<<"\n";
	}
	*/
	
	return 0;
}
/*
4 3
2 1 0 3

5 5
1 2 3 4 5
*/
