#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int N=2e5+5;
int n,q,sa[N][2][2],qa[2][2],ans;
string s[N][2],qs[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(int j=0;j<=1;j++){
			int l=s[i][j].size();
			int flag=0;
			for(int k=0;k<l;k++){
				if(s[i][j][k]=='b'){
					flag=1;
					continue;
				}
				if(s[i][j][k]=='a'){
					sa[i][j][flag]++;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		for(int j=0;j<=1;j++){
			for(int k=0;k<=1;k++){
				qa[j][k]=0;
			}
		}
		cin>>qs[0]>>qs[1];
		for(int j=0;j<=1;j++){
			int l=qs[j].size();
			int flag=0;
			for(int k=0;k<l;k++){
				if(qs[j][k]=='b'){
					flag=1;
					continue;
				}
				if(qs[j][k]=='a'){
					qa[j][flag]++;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(sa[j][0][0]<=qa[0][0]&&sa[j][0][1]<=qa[0][1]&&sa[j][1][0]<=qa[1][0]&&sa[j][1][1]<=qa[1][1]&&sa[j][0][0]-sa[j][1][0]==qa[0][0]-qa[1][0]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

