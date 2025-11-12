#include<bits/stdc++.h>
using namespace std;
int n,T;
string q,to,a[200005],t[200005];    
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;++i)cin>>a[i]>>t[i];
	while(T--){
		int ans=0;
		cin>>q>>to;
		for(int i=1;i<=n;++i){
			int ft=to.find(t[i]),yes=1,as=a[i].size(),ts=t[i].size();
			if(ft<=t[i].size()&&ft>=0){
				for(int j=0;j<ft;++j){
					if(q[j]!=to[j]){
						yes=0;
						break;
					}
				}
				if(yes==0)continue;
				for(int j=ft;j<ft+as;++j){
					if(q[j]!=a[i][j-ft]){
						yes=0; 
						break;
					}
				}
				if(yes==0)continue;
				for(int j=ft+as;j<q.size();++j){
					if(q[j]!=to[j-as+ts]){
						yes=0;
						break;
					}
				}
				if(yes==0)continue;
				ans++;
			}	
		}
		printf("%d\n",ans);
	}
	return 0;
}
