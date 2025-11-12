#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,L=5e6+5,P=131;
string s[N][5],t1,t2;
int ls[N],lt;
unsigned long long hs[N][5],ht1[L],ht2[L],powp[L];
void Hash_s(int x,int y){
	string st=s[x][y];
	int len=ls[x];
	for(int i=0;i<len;i++) hs[x][y]=hs[x][y]*P+(st[i]-'a'+1);
}
void Hash_t(){
	for(int i=1;i<=lt;i++) ht1[i]=ht1[i-1]*P+(t1[i-1]-'a'+1);
	for(int i=1;i<=lt;i++) ht2[i]=ht2[i-1]*P+(t2[i-1]-'a'+1);
}
bool check(int x,int y){
	int len=ls[x];
	bool equal1=(hs[x][1]==ht1[y]-ht1[y-len]*powp[len]);
	bool equal2=(hs[x][2]==ht2[y]-ht2[y-len]*powp[len]);
	return (equal1 && equal2);
}
bool fl[L],fr[L];
int b[N][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	powp[0]=1;
	for(int i=1;i<=L-5;i++) powp[i]=powp[i-1]*P;
	int n,q;
	cin>>n>>q;
	bool flgB=1;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		ls[i]=s[i][1].size();
		Hash_s(i,1),Hash_s(i,2);
		for(int j=0;j<ls[i];j++){
			for(int k=1;k<=2;k++){
				if(s[i][k][j]=='b'){
					if(b[i][k]) flgB=0;
					else b[i][k]=j;
				}
				else if(s[i][k][j]!='a') flgB=0;
			}
		}
	}
	while(q--){
		cin>>t1>>t2;
		lt=t1.size();
		int lt2=t2.size();
		if(lt!=lt2){
			cout<<0<<'\n';
			continue;
		}
		Hash_t();
		fl[0]=fr[lt+1]=1;
		int b1=0,b2=0;
		for(int i=1;i<=lt;i++){
			fl[i]=0,fr[lt-i+1]=0;
			if(t1[i-1]==t2[i-1]) fl[i]|=fl[i-1];
			if(t1[lt-i]==t2[lt-i]) fr[lt-i+1]|=fr[lt-i+2];
			if(t1[i-1]!=t2[i-1]){
				if(t1[i-1]=='b'){
					if(b1) flgB=0;
					else b1=i-1;
				}
				if(t2[i-1]=='b'){
					if(b2) flgB=0;
					else b2=i-1;
				}
			}
		}
		int ans=0;
		if(flgB){
			int l=min(b1,b2),r=max(b1,b2);
			while(l-1>=0 && t1[l-1]=='a' && t2[l-1]=='a') l--;
			while(r+1<lt && t1[r+1]=='a' && t2[r+1]=='a') r++;
			for(int i=1;i<=n;i++){
				if(b2-b1==b[i][2]-b[i][1] && b[i][1]<=b1-l && ls[i]-1-b[i][2]<=r-b2) ans++;
			}
		}
		else{
			for(int i=1;i<=lt;i++){
				for(int j=1;j<=n;j++){
					if(fl[i-ls[j]] && fr[i+1] && check(j,i)) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
