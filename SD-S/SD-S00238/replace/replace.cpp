#include<bits/stdc++.h>
using namespace std;
long long m,n,ss[200010][5],f[3],f1[3],e,ans;
string s[200010][3],qs1,qs2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>s[i][1]>>s[i][2];
		for(int j=0;j<=s[i][1].length()-1;j++){
			e=1;
			if(s[i][1][j]!='b'){
				ss[i][e]++;
			}
			else e++;
		}
		for(int j=0;j<=s[i][2].length()-1;j++){
			e=3;
			if(s[i][2][j]!='b'){
				ss[i][e]++;
			}
			else e++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>qs1>>qs2;
		for(int i=0;i<=qs1.length()-1;i++){
			e=1;
			if(qs1[i]!='b'){
				f[e]++;
			}
			else e++;
		}
		for(int i=0;i<=qs2.length()-1;i++){
			e=1;
			if(qs2[i]!='b'){
				f1[e]++;
			}
			else e++;
		}
		for(int i=1;i<=m;i++){
			if(ss[i][1]-ss[i][3]==f[1]-f1[1]&&ss[i][1]<=f[1]&&ss[i][2]<=f[2]&&ss[i][3]<=f1[1]&&ss[i][4]<=f1[2])ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}


