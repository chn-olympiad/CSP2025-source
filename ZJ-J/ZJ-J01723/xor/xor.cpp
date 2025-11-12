#include<bits/stdc++.h>
using namespace std;
int n, k;
string aaa;
int ma=0;
struct node{
	int a;
	string s;
}a[500010];
void dfs(int l, string aa,int st){
	if(l>=n){
		ma=max(st,ma);
	}
	int r=l+1;
	while(r<=n){
		for(int i=l;i<=r;i++){
			for(int j=0;j<8;j++){
				if(aa[j]==a[i].s[j])
					aa[j]='0';
				else{
					aa[j]='1';
				}
			}
		}
		if(aa==aaa)
			dfs(r+1,"00000000",st+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		int x=a[i].a;
		int cnt=128;
		for(int j=0;j<8;j++){
			if(x>=cnt)	{
				a[i].s[j]='1';
				x-=cnt;
			}
			else {
				a[i].s[j]='0';
			}
			cnt/=2;
		}
	}
	cnt=128;
	for(int j=0;j<8;j++){
		if(k>=cnt)	{
			aaa[j]='1';
			k-=cnt;
		}
		else {
			aaa[j]='0';
		}
		cnt/=2;
	}
	dfs(1,"00000000",0);
	cout<<ma;
	return 0;
}
