#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
#define ll long long
const int MAXN=2e5+5;
struct node{
	ll l,r,pl;
}ns[MAXN],qsn;
ll n,q,f=1;
string s[MAXN][15],t1,t2;
int dfs(ll w,ll j){
	if(j>n){
		return 0;
	}
	if(j==n){
		if(w==qsn.l+qsn.pl){
			return 1;
		}
		return 0;
	}
	ll anss=dfs(w,j+1);
	if(w>=ns[j].l&&t1.size()-w>=ns[j].r){
		anss+=dfs(w+ns[j].pl,j+1);
	}
	return anss;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int j=0,f1=0;
		while(s[i][1][j++]=='a'){
			ns[i].l++;
			if(s[i][2][j-1]=='b'){
				f1=-1;
			}
			ns[i].pl+=f1;
		}
		if(f1==-1){
			ns[i].r=s[i][1].size()-j;
		}else{
			f1=1;
			while(j<s[i][1].size()&&s[i][1][j++]=='a'){
				ns[i].r++;
				ns[i].pl+=f1;
				if(s[i][2][j-1]=='b'){
					f1=0;
				}
			}
		}
	}
	while(q--){
		cin>>t1>>t2;
		int j=0,f1=0;
		while(t1[j++]=='a'){
			qsn.l++;
			if(t2[j-1]=='b'){
				f1=-1;
			}
			qsn.pl+=f1;
		}
		if(f1==-1){
			qsn.r=t1.size()-j;
		}else{
			f1=1;
			while(j<t1.size()&&t1[j++]=='a'){
				qsn.r++;
				qsn.pl+=f1;
				if(t2[j-1]=='b'){
					f1=0;
				}
			}
		}
		cout<<dfs(qsn.l,1)<<"\n";
	}
	return 0;
}
