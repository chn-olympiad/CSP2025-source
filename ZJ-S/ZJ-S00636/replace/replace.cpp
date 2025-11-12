#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=2e5+5,p=202511017;

int n,q;
string s1,s2,t1,t2;
struct node{
	int h1;	
	int h2;
	bool operator < (node nd)const{
		if(h1!=nd.h1)return h1<nd.h1;
		return h2<nd.h2;
	}
};
map<node,int>mp;
vector<node>v[N];int cnt=0;
bool gl[N],gr[N];
bitset<p+5>mgl,mgr;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int h1=0,h2=0,hl=0,hr=0;
		int m=s1.size(),l=m+1,r=-1;
		for(int j=0;j<m;j++)
			if(s1[j]!=s2[j]){
				l=min(l,j);
				r=max(r,j);
			}
		for(int j=0;j<l;j++)
			hl=(hl*27%p+s1[j]-'a'+1)%p;
		for(int j=r+1;j<m;j++)
			hr=(hr*27%p+s1[j]-'a'+1)%p;
			
		for(int j=l;j<=r;j++)
			h1=(h1*27%p+s1[j]-'a'+1)%p;
		for(int j=l;j<=r;j++)
			h2=(h2*27%p+s2[j]-'a'+1)%p;
			
//		cout<<i<<" : "<<h1<<" "<<h2<<" "<<hl<<" "<<hr<<"\n";
			
		node t;t.h1=h1;t.h2=h2;
		if(mp[t]==0)mp[t]=++cnt;
		int pos=mp[t];
		node tt;tt.h1=hl;tt.h2=hr;
		v[pos].push_back(tt);
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int m=t1.size(),l=m+1,r=-1;
		for(int i=0;i<m;i++)
			if(t1[i]!=t2[i]){
				l=min(l,i);
				r=max(r,i);
			}
		int h1=0,h2=0;
		for(int i=l;i<=r;i++)
			h1=(h1*27%p+t1[i]-'a'+1)%p;
		for(int i=l;i<=r;i++)
			h2=(h2*27%p+t2[i]-'a'+1)%p;
		node t;t.h1=h1;t.h2=h2;
		int pos=mp[t],ans=0;
		if(pos==0){
			cout<<"0\n";
			continue;
		}
		if((int)v[pos].size()<=20){
			for(int i=0;i<(int)v[pos].size();i++)
				gl[i]=0,gr[i]=0;
			int pw=1,s=0;
			for(int j=0;j<(int)v[pos].size();j++)
				if(s==v[pos][j].h1)gl[j]=1;
			for(int i=l-1;i>=0;i--){
				s=(s+pw*(t1[i]-'a'+1)%p)%p;
				pw=pw*27%p;
				for(int j=0;j<(int)v[pos].size();j++)
					if(s==v[pos][j].h1)gl[j]=1;
			}
			s=0;
			for(int j=0;j<(int)v[pos].size();j++)
				if(s==v[pos][j].h2)gr[j]=1;
			for(int i=r+1;i<m;i++){
				s=(s*27%p+t1[i]-'a'+1)%p;
				for(int j=0;j<(int)v[pos].size();j++)
					if(s==v[pos][j].h2)gr[j]=1;
			}
			for(int i=0;i<(int)v[pos].size();i++)
				if(gl[i]&&gr[i])ans++;
		}else{
			int pw=1,s=0;
			mgl[s]=1;
			for(int i=l-1;i>=0;i--){
				s=(s+pw*(t1[i]-'a'+1)%p)%p;
				pw=pw*27%p;
				mgl[s]=1;
			}
			s=0;
			mgr[s]=1;
			for(int i=r+1;i<m;i++){
				s=(s*27%p+t1[i]-'a'+1)%p;
				mgr[s]=1;
			}
			for(int i=0;i<(int)v[pos].size();i++)
				if(mgl[v[pos][i].h1]&&mgr[v[pos][i].h2])ans++;
			pw=1,s=0;
			mgl[s]=0;
			for(int i=l-1;i>=0;i--){
				s=(s+pw*(t1[i]-'a'+1)%p)%p;
				pw=pw*27%p;
				mgl[s]=0;
			}
			s=0;
			mgr[s]=0;
			for(int i=r+1;i<m;i++){
				s=(s*27%p+t1[i]-'a'+1)%p;
				mgr[s]=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
