#include<bits/stdc++.h>
using namespace std;
int ans,n,q,flag,f[200050];
string stx,sty,st1[200050],st2[200050];
void dfs(string stxx,int kk){
	if(stxx==sty){
		ans++;
		return;
	}
		
	for(int i=0;i<stxx.size();i++){
		for(int j=kk;j<=n;j++){//if(i.size)
		//cout<<f[4]<<endl;
			if(f[j]!=1){
				continue;
			}
			flag=1;
			for(int k=0;k<st1[j].size();k++){
				if(st1[j][k]!=stxx[i+k]){
					flag=0;
					break;
				}
			}
			if(flag){//cout<<j<<' '<<i<<' '<<f[4]<<endl;
				dfs(stxx,j+1);
				for(int k=0;k<st1[j].size();k++){
					stxx[k+i]=st2[j][k];
				}
				f[j]=0;
				dfs(stxx,1);
				//f[j]=1;
			}		
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>st1[i]>>st2[i];
	}
	for(int i=1;i<=q;i++){
		ans=0;//cout<<1<<endl;
		for(int j=1;j<200050;j++)
			f[j]=1;
		cin>>stx>>sty;
		dfs(stx,1);
		cout<<ans<<endl;
	}
}
