#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,mod=1000000007;
int n,a[N][4],c[N],s[4],d[N],T; 
vector<int> ch[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;int ans=0;s[0]=s[1]=s[2]=s[3]=0;
		for(int i=1;i<=3;i++) ch[i].clear();
		for(int i=1;i<=n;i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int tmp=max(a[i][1],max(a[i][2],a[i][3]));
//			cout<<tmp<<'\n';
			ans+=tmp;
			for(int j=1;j<=3;j++){
				if(tmp==a[i][j]){
					s[j]++;ch[j].push_back(i);
					break;
				}
			}
		}
		int flag=0;
		for(int i=1;i<=3;i++){
			if(s[i]>n/2){
				flag=i;
				break;
			}
		}
		if(!flag) {
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=s[flag];i++) {
			d[i]=1e9;
			for(int j=1;j<=3;j++){
				if(j!=flag) d[i]=min(d[i],a[ch[flag][i-1]][flag]-a[ch[flag][i-1]][j]); 
			}
		}
		sort(d+1,d+1+s[flag]);
		for(int i=1;i<=s[flag]-n/2;i++) ans-=d[i];
		cout<<ans<<'\n'; 
	}
	return 0;
}

