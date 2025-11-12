#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
int tr1[1600010][26],tr2[1600010][26],cnt1,cnt2;
int tg1[1600010],tg2[1600010];
vector<int> ind1[1600010];
vector<int> ind2[1600010];
void build(string s1,string s2,int ind){
	if(s1==s2) return;
	int u=0;
	for(int i=s1.length()-1;i>=0;i--){
		int t=s1[i]-'a';
		if(!tr1[u][t]) tr1[u][t]=++cnt1;
		u=tr1[u][t];
	}
	tg1[u]++;
	ind1[u].push_back(ind);
	u=0;
	for(int i=s1.length()-1;i>=0;i--){
		int t=s2[i]-'a';
		if(!tr2[u][t]) tr2[u][t]=++cnt2;
		u=tr2[u][t];
	}
	tg2[u]++;
	ind2[u].push_back(ind);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		build(s1,s2,i);
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int l,r;
		for(l=0;l<t1.length();l++){
			if(t1[l]!=t2[l]) break;
		}
		for(r=t1.length()-1;r>=0;r--){
			if(t1[r]!=t2[r]) break;
		}
		int ans=0;
		for(int k=t1.length()-1;k>=r;k--){
			int u1=0,u2=0;
			for(int j=k;j>=0;j--){
				int f1=t1[j]-'a',f2=t2[j]-'a';
				if(!tr1[u1][f1]||!tr2[u2][f2]) break;
				u1=tr1[u1][f1];
				u2=tr2[u2][f2];
				if(j<=l&&tg1[u1]&&tg2[u2]){
					int l1=0,l2=0;
					while(l1<ind1[u1].size()&&l2<ind2[u2].size()){
						while(l1<ind1[u1].size()&&ind1[u1][l1]<ind2[u2][l2]) l1++;
						while(l2<ind2[u2].size()&&ind2[u2][l2]<ind1[u1][l1]) l2++;
						if(ind1[u1][l1]==ind2[u2][l2]){
							ans++;
							l1++;
							l2++;
						} 
						else if(ind1[u1][l1]<ind2[u2][l2]) l1++;
						else l2++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
