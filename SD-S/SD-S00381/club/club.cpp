#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0;
	char p=getchar();
	while(p<'0'||p>'9'){
		p=getchar();
	}
	while(p>='0'&&p<='9'){
		s*=10;
		s+=p-'0';
		p=getchar();	
	}
	return s;
}
int tmp[5],ans;
vector<int>a[5];
void solve(){
	a[1].clear(),a[2].clear(),a[3].clear();
	ans=0;
	int n=read();
	int m=n>>1;
	for(int i=1;i<=n;++i){
		tmp[1]=read(),tmp[2]=read(),tmp[3]=read();
		int frt=0,sec=0;
		for(int j=1;j<=3;++j){
			if(tmp[frt]<=tmp[j]){
				sec=frt;
				frt=j;	
			}
			else{
				if(tmp[sec]<=tmp[j]){
					sec=j;
				}
			}
		}
		a[frt].push_back(tmp[frt]-tmp[sec]);
		ans+=tmp[frt];
	}
	for(int i=1;i<=3;++i){
		if(a[i].size()>m){
			sort(a[i].begin(),a[i].end());
			int siz=a[i].size();
			for(int j=0;m+j+1<=siz;++j){
				ans-=a[i][j];	
			}
			break ;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();	
	}
	return 0;
}

