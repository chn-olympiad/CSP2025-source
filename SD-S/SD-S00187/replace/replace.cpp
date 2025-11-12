#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,M=1e3+5;
const int INF=0x3f3f3f3f;
string a,b;
int n,q;
int flag=0;
void ch(string s){
	int l=s.length();
	int f=0;
	for(int i=0;i<l;i++){
		if(s[i]!='a'&&s[i]!='b'){
			flag=1; return;
		}
		if(s[i]=='b') f=1;
	}
	if(f!=1) flag=1;
}
int ans;
int sum[M][M];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int k=1;k<=n;k++){
		cin>>a>>b;
		ch(a);
		if(flag==1) return 0;
		ch(b);
		if(flag==1) return 0;
		int sw=0;
		int st=0;
		int l=a.length();
		for(int i=0;i<l;i++){
			if(sw==1){
				st++;
			}
			if(a[i]=='b'&&b[i]=='b') break;
			if(a[i]=='b'||b[i]=='b') sw^=1;
		}
		sum[k][1]=st;
		sum[k][2]=a.length();
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		ch(t1);
		if(flag==1) return 0;
		ch(t2);
		if(flag==1) return 0;
		if(t1.length()!=t2.length()){
			cout<<0<<endl; continue;
		}
		int l=t1.length();
		int sw=0;
		int st=0;
		for(int i=0;i<l;i++){
			if(sw==1){
				st++;
			}
			if(t1[i]=='b'&&t2[i]=='b') break;
			if(t1[i]=='b'||t2[i]=='b') sw^=1;
		}
		for(int i=1;i<=n;i++){
			if(sum[i][1]==st&&l>=sum[i][2]) ans++;
		}
		cout<<ans;
	}
	return 0;
}

