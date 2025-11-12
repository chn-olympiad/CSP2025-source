#include<bits/stdc++.h>
using namespace std;
const int N=2e5+12;
int n,q;
string c1[N],c2[N],t[5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>c1[i]>>c2[i];
	while(q--){
		int ans=0,qi=-1;string d,b;
		cin>>t[1]>>t[2];
		if(t[1].size()!=t[2].size()){printf("0\n");continue;}
		for(int i=0;i<t[1].size();i++) if(t[1][i]!=t[2][i]){
			if(qi==-1) qi=i;
			d+=t[1][i];b+=t[2][i];
		}
		for(int i=1;i<=n;i++) if(d==c1[i]&&b==c2[i]) ans++;
		string d1=d,d2=d,b1=b,b2=b;
		for(int i=qi-1;i>=0;i--){
			d1=t[1][i]+d1;b1=t[2][i]+b1;
			for(int j=1;j<=n;j++) if(d1==c1[j]&&b1==c2[j]) ans++;
		}
		for(int i=qi+d.size();i<t[1].size();i++){
			d2=d2+t[1][i];b2=b2+t[2][i];
			for(int j=1;j<=n;j++) if(d2==c1[j]&&b2==c2[j]) ans++;
		}
		d1=d;b1=b;
		for(int i=qi-1;i>=0;i--){
			d1=t[1][i]+d1;d2=d1;
			b1=t[2][i]+b1;b2=b1;
			for(int j=qi+d.size();j<t[1].size();j++){
				d2=d2+t[1][j];b2=b2+t[2][j];
				for(int k=1;k<=n;k++) if(d2==c1[k]&&b2==c2[k]) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}