#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s1[200005][3],s2[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i][1]>>s1[i][2];
	}for(int i=1;i<=m;i++){
		cin>>s2[i][1]>>s2[i][2];
		ans=0;
		for(int j=1;j<=n;j++){
			int a1,a2,b1,b2;
			string x1,x2,y1,y2;
			a1=s2[i][1].find(s1[j][1]);
			b1=a1+s1[j][1].size();
			a2=s2[i][2].find(s1[j][2]);
			b2=a2+s1[j][2].size();
			x1=s2[i][1].substr(0,a1);
			y1=s2[i][1].substr(b1);
			x2=s2[i][2].substr(0,a2);
			y2=s2[i][2].substr(b2);
			if(x1==x2&&y1==y2)ans++;
		}cout<<ans<<endl;
	}
	return 0;
} 