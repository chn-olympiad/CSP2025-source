#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10,M=1e6+10;
const int INF=0x3f3f3f3f;

int n,m;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	string a;
	cin>>a;
	int ans=0;
	for(auto c:a){
		if(c=='0'){
			++ans;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
