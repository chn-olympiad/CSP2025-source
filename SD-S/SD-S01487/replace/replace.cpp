#include<iostream>
#include<cstring>
#define ll long long

using namespace std;

const int N=1e3+10;

int n,q,nxt[N][N],nxt2[N][N],cnt=0,st,ed,ans=0;

struct tihuan{
	string s1,s2;
}s[N];

void getnxt(int x){
	nxt[x][0]=-1,nxt[x][1]=0;
	for(int i=1;i<s[x].s1.size();i++){
		int j=i;
		while(j&&s[x].s1[i]!=s[x].s1[j]) j=nxt[x][j];
		if(s[x].s1[i]==s[x].s1[j]) nxt[x][i+1]=j;
		else nxt[x][i+1]=0;
	}
	nxt2[x][0]=-1,nxt2[x][1]=0;
	for(int i=1;i<s[x].s2.size();i++){
		int j=i;
		while(j&&s[x].s2[i]!=s[x].s2[j]) j=nxt2[x][j];
		if(s[x].s2[i]==s[x].s2[j]) nxt2[x][i+1]=j;
		else nxt2[x][i+1]=0;
	}
}

void bi(int x,string t1,string t2){
	int j=0,cc=0;
	for(int i=0;i<t1.size();i++){
		while(j&&(s[x].s1[j]!=t1[i])) j=nxt[x][j];
		while(j&&s[x].s2[j]!=t2[i]) j=nxt2[x][j];
		if(s[x].s1[j]==t1[i]&&s[x].s2[j]==t2[i]) j++;
		if(j==s[x].s1.size()){
			if(st>=i-j+1&&ed<=i){
				ans++;
//				cout<<st<<" "<<ed<<"\n";
			}
		}
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
		getnxt(i);
	}
	
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int cnn=0;
		ans=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				if(!cnn) st=i;
				cnn=1;
				ed=i;
			}
		}
		for(int i=1;i<=n;i++){
			bi(i,t1,t2);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
