#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	string s[2];
	int len;
}a[N];
string t[2];
long long n,q,cnt,cntt,ans;
bool cmp(node x,node y){
	return x.len<y.len;
}
/*bool kmp(int x,int stt,int tll){
	int len=a[x].len,p=0;
	stt++,tll++;
	for(int i=2;i<=len;i++){
		while(p&&a[x].s[0][i]!=a[x].s[0][p]){
			p=nxt[p];
		}
		if(a[x].s[0][i]==a[x].s[0][p]){
			p++;
		}
		nxt[i]=p;
	}
	p=0;
	for(int i=1;i<=t[0].size();i++){
		while(p&&a[x].s[0][p]!=t[0][i]){
			p=nxt[p];
		}
		if(a[x].s[0][p]==t[0][i]){
			p++;
		}
		if(p==len){
			if(i-len+1<=stt&&i>=tl){
				
			}
			p=nxt[p];
		}
	}
}
bool kmpp(int x,int stt,int tll){
	int len=a[x].len,p=0;
	stt++,tll++;
	for(int i=2;i<=len;i++){
		while(p&&a[x].s[1][i]!=a[x].s[0][p]){
			p=nxt[p];
		}
		if(a[x].s[0][i]==a[x].s[0][p]){
			p++;
		}
		nxt[i]=p;
	}
	p=0;
	for(int i=1;i<=t[0].size();i++){
		while(p&&a[x].s[0][p]!=t[0][i]){
			p=nxt[p];
		}
		if(a[x].s[0][p]==t[0][i]){
			p++;
		}
		if(p==len){
			if(i-len+1<=stt&&i>=tl){
				return true;
			}
			p=nxt[p];
		}
	}
}*/
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s[0]>>a[i].s[1];
	}
	while(q--){
		ans=0;
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<"0\n";
			continue;
		}
		int fl;
		for(int k=1;k<=n;k++){
			for(int i=0;i<t[0].size()-a[k].s[0].size()+1;i++){
				fl=0;
				for(int j=0;j<i;j++){
					if(t[0][j]!=t[1][j]){
						fl=1;
						break;
					}
				}
				if(fl) break;
				for(int j=i;j<i+a[k].s[0].size();j++){
					if(t[0][j]!=a[k].s[0][j-i]||t[1][j]!=a[k].s[1][j-i]){
						fl=1;
						break;
					}
				}
				if(fl) continue;
				for(int j=i+a[k].s[0].size();j<t[0].size();j++){
					if(t[0][j]!=t[1][j]){
						fl=1;
						break;
					}
				}
				if(fl) continue;
				else{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
/*	for(int i=1;i<=n;i++){
		cin>>a[i].s[0]>>a[i].s[1];
		a[i].len=a[i].s[0].size();
	}
	sort(a+1,a+n+1,cmp);
	while(q--){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<t[0].size();i++){
			if(t[0][i]!=t[1][i]){
				st=i;
				break;
			}
		}
		for(int i=t[0].size()-1;i>=0;i--){
			if(t[0][i]!=t[1][i]){
				tl=i;
				break;
			}
		}
		t[0]=" "+t[0];
		t[1]=" "+t[1];
		int l=1,r=n;
		while(l<r){
			int mid=l+r>>1;
			if(a[mid].len<tl-st+1){
				l=mid+1;
			}
			else{
				r=mid;
			}
		}
		for(int i=l;i<=n;i++){
			if(kmp(i,st,tl)){
				
			}
		}
	}*/
	return 0;
}

