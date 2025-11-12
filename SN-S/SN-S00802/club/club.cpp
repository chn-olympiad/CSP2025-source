#include<bits/stdc++.h>
using namespace std;
int T;
int maxn=0,minn=99999;
bool cmp(int x,int y){
	return x>y;
}
int n;
int s[100005];
int t[100005];
int u[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	cin>>n;
	int sco=0,sct=0,sch=0;
	int cnts=0,cntt=0,cntu=0;
	for(int q=1;q<=T;q++){
		for(int i=1;i<=n;i++){
			cin>>s[i]>>t[i]>>u[i];
		}
		for(int i=1;i<=n;i++){
			maxn=max(s[i],maxn);
			maxn=max(t[i],maxn);
			maxn=max(u[i],maxn);
			if(s[i]==maxn && cnts<=n/2){
				sco+=s[i];
				cnts++;
				continue;
			}
			else if(t[i]==maxn && cntt<=n/2){
				sct+=t[i];
				cntt++;
				continue;
			}
			else if(u[i]==maxn && cntu<=n/2){
				sch+=u[i];
				cntu++;
				continue;
			}
			else if(cnts>n/2 && cntt>n/2 && cntu>n/2){
				minn=min(s[i],minn);
				minn=min(t[i],minn);
				minn=min(u[i],minn);
				if(s[i]==maxn && t[i]==minn && cnts>n/2){
					sch+=u[i];
					cntu++;
					continue;
				}
				else if(t[i]==maxn &&s[i]==minn && cntt>n/2){
					sch+=u[i];
					cntu++;
					continue;
				}
				else if(u[i]==maxn &&s[i]==minn && cntu>n/2){
					sct+=t[i];
					cntt++;
					continue;
				}
				else if(t[i]==maxn &&u[i]==minn && cntt>n/2){
					sco+=s[i];
					cnts++;
					continue;
				}
				else if(u[i]==maxn &&t[i]==minn && cntu>n/2){
					sco+=s[i];
					cnts++;
					continue;
				}
				else if(s[i]==maxn &&u[i]==minn && cnts>n/2){
					sct+=t[i];
					cnts++;
					continue;
				}
			}
		}
		cout<<sco+sct+sch<<endl;
		sco=0,sct=0,sch=0;		
	}
	return 0;
} 
