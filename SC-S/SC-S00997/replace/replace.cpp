#include<bits/stdc++.h>
#include<string>
using namespace std;

const int N=2e5+10,M=1e6+10;
const int INF=0x3f3f3f3f;

int n,m,q;

string a[N][3];
int flag=1;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=q;++i){
		string c,d;
		cin>>c>>d;
		long long ans=0;
		for(int j=1;j<=n;++j){
			if(c.find(a[j][0])<0||d.find(a[j][1])<0){
				continue;
			}
			++ans;
		}
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
