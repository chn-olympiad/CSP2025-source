#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10,M=5e6+10;
int n,q;
int p=1;
string s1[N],s2[N],t1[N],t2[N];
int d[N],pr[N];
int ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int len=s1[i].size();
		int sum=0;
		for(int j=0;j<len;j++){
			if(s1[i][j]=='a'||s1[i][j]=='b'){
				if(s1[i][j]=='b')sum++;
			}else p=0;
		}if(sum!=1)p=0;
	}if(p){
		map<ll,ll>mp;
		for(int i=1;i<=n;i++){
			int len=s1[i].size();
			ll sum=0;
			for(int j=0;j<len;j++){
				sum++;
				if(s1[i][j]=='b')d[i]+=j,pr[i]=sum;
				if(s2[i][j]=='b')d[i]-=j;
			}
		}for(int i=1;i<=q;i++){
			cin>>t1[i]>>t2[i];
			int ans=0;
			if(t1[i].size()==t2[i].size()){
				cout<<"0\n";
				continue;
			}int len=t1[i].size(),dd=0,pre,s=0;
			for(int j=0;j<len;j++){
				s++;
				if(t1[i][j]=='b')dd+=j,pre=s;
				if(t2[i][j]=='b')dd-=j;
			}for(int j=1;j<=n;j++){
				if(pr[j]>=s&&dd==d[j])ans++;
			}cout<<ans<<endl;
		}
	}for(int i=1;i<=q;i++){
		ans=0;
		cin>>t1[i]>>t2[i];
		if(t1[i].size()!=t2[i].size()){
			cout<<"0\n";
			continue;
		}int len=t1[i].size();
		int L=-1,R=-1;
		for(int j=0;j<len;j++){
			if(t1[i][j]!=t2[i][j]){
				if(L==-1)L=j;
				R=j;
			}
		}
		for(int j=1;j<=n;j++){
			int l=s1[j].size();
			if(l<R-L+1)continue;
			int st=0;
			if(R!=-1)st=R-l+1;
			if(st<0)st=0;
			for(;st<len;st++){
				int x=1;
				if(st+l>len)break;
				for(int k=0;k<l;k++){
					if(s1[j][k]!=t1[i][st+k]){
						x=0;
						break;
					}if(s2[j][k]!=t2[i][st+k]){
						x=0;
						break;
					}
				}ans+=x;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
