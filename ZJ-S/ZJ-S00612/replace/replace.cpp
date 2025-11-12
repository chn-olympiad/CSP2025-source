//我该在哪里停留？ 
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n,q,len[MAXN],change[MAXN][3];
string s[MAXN][2],t1,t2;
bool B=true;
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1],len[i]=s[i][0].size(),s[i][0]=' '+s[i][0],s[i][1]=' '+s[i][1];
		if(B) for(int j=1;j<=len[i];j++) if(s[i][0][j]>'b'||s[i][1][j]>'b'){
			B=false;
			break;
		}
	} if(B) for(int i=1;i<=n;i++){
		for(int j=1;j<=len[i];j++) if(s[i][0][j]==s[i][1][j]) change[i][0]++;
		else break;
		for(int j=len[i];j;j--) if(s[i][0][j]==s[i][1][j]) change[i][2]++;
		else break;
	} while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		} int Len=t1.size(),ans=0;
		t1=' '+t1,t2=' '+t2;
		if(B){
			int l=0,r=0;
			for(int i=1;i<=Len;i++) if(t1[i]==t2[i]) l++;
			else break;
			for(int i=Len;i;i--) if(t1[i]==t2[i]) r++;
			else break;
			for(int i=1;i<=n;i++) if(l>=change[i][0]&&r>=change[i][2]&&len[i]-change[i][0]-change[i][2]==Len-l-r&&s[i][0][change[i][0]+1]==t1[l+1]) ans++;
			cout<<ans<<"\n";
			continue;
		} string le="",ri;
		cout<<"0\n";
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
