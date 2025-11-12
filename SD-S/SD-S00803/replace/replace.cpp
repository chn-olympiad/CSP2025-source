#include<iostream>
#include<vector>
using namespace std;
const int N=2e5+5;
int n,q;
int szs[N][3];
int szt[N][3];
int mp[N];
vector<char> a;
string s[N][3],t[N][3];
vector<int> nxt[N][3];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		char c;
		for(int j=1;j<=2;j++){
			c=getchar();
			while(c>='a'&&c<='z') a.push_back(c),c=getchar();
			szs[i][j]=a.size();
			s[i][j].resize(szs[i][j]+1);
			for(int k=1;k<=szs[i][j];k++) s[i][j][k]=a[k-1];
			a.clear(); 
		}
	}
	for(int i=1;i<=q;i++){
		char c;
		for(int j=1;j<=2;j++){
			c=getchar();
			while(c>='a'&&c<='z') a.push_back(c),c=getchar();
			szt[i][j]=a.size();
			t[i][j].resize(szt[i][j]+1);
			for(int k=1;k<=szt[i][j];k++) t[i][j][k]=a[k-1];
			a.clear(); 
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=2;b++){
			int m=szs[a][b];
			nxt[a][b].resize(m+1);
//			cout<<a<<" "<<b<<'\n';
			for(int i=2,j=0;i<=m;i++){
				while(j&&s[a][b][i]!=s[a][b][j+1]) j=nxt[a][b][j];
				if(s[a][b][i]==s[a][b][j+1]) j++;
				nxt[a][b][i]=j;
			}
//			for(int i=1;i<=m;i++) cout<<nxt[a][b][i]<<' ';
//			cout<<'\n';
		}
	}
//	for(int i=1;i<=q;i++){
//		for(int j=1;j<=2;j++){
//			int m=szt[i][j];
//			pre[i][j]="";
//			for(int k=1;k<=m;k++) pre[i][j][k]=pre[i][j][k-1]+t[i][j][k],cout<<pre[i][j][k]<<" ";
//			cout<<'\n';
//		}
//	}
	for(int a=1;a<=q;a++){
		int ans=0;
		for(int b=1;b<=n;b++){
//			cout<<a<<" "<<b<<' ';
			int ss=szt[a][1],tt=szs[b][1];
//			cout<<ss<<" "<<tt<<'\n';
			for(int i=1;i<=ss;i++) mp[i]=0;
			for(int i=1,j=0;i<=ss;i++){
//				cout<<t[a][1][i]<<" "<<s[b][1][j+1]<<'\n';
				while(j&&t[a][1][i]!=s[b][1][j+1]) j=nxt[b][1][j];
				if(t[a][1][i]==s[b][1][j+1]) j++;
//				cout<<j<<'\n';
				if(j==tt){
					mp[i-j+1]=1;
//					cout<<"WA"<<' '<<nxt[b][1][j]<<'\n';
					j=nxt[b][1][j];
				}
			}
//			cout<<'\n';
			for(int i=1,j=0;i<=ss;i++){
				while(j&&t[a][2][i]!=s[b][2][j+1]) j=nxt[b][2][j];
				if(t[a][2][i]==s[b][2][j+1]) j++;
//				cout<<j<<'\n';
				if(j==tt){
//					cout<<i-j+1<<' ';
					if(mp[i-j+1]==1&&t[a][1].substr(1,i-j)==t[a][2].substr(1,i-j)&&t[a][1].substr(i-j+1+tt,szt[a][1])==t[a][2].substr(i-j+1+tt,szt[a][2])) ans++;
					j=nxt[b][2][j];
				}
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
