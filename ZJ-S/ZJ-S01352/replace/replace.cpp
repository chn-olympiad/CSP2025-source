#include<bits/stdc++.h>
using namespace std;
int n,q,f[5000010],nxt[5000010],n1[200010],n2[200010],sum1,v1,sum2,v2,ans;
string s1[200010],s2[200010],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		n1[i]=s1[i].size();
		n2[i]=s2[i].size();
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		int m1=t1.size();
		int m2=t2.size();
		if(m1!=m2){
			cout<<"0\n";
			return 0;
		}
		t1=" "+t1;
		t2=" "+t2;
		for(int k=1;k<=n;k++){
			sum1=sum2=v1=v2=0;
			memset(nxt,0,sizeof nxt);
			memset(f,0,sizeof f);
			for(int i=2,j=0;i<=n1[k];i++){
				while(j>0&&s1[k][i]!=s1[k][j+1]) j=nxt[j];
				if(s1[k][i]==s1[k][j+1]) j++;
				nxt[i]=j;
			}
			for(int i=1,j=0;i<=m1;i++){
				while(j>0&&(j==n1[k]||t1[i]!=s1[k][j+1])) j=nxt[j];
				if(t1[i]==s1[k][j+1]) j++;
				f[i]=j;
				if(f[i]==n1[k]) sum1++,v1=i;
			}
			if(sum1!=1) continue;
			memset(nxt,0,sizeof nxt);
			memset(f,0,sizeof f);
			for(int i=2,j=0;i<=n2[k];i++){
				while(j>0&&s2[k][i]!=s2[k][j+1]) j=nxt[j];
				if(s2[k][i]==s2[k][j+1]) j++;
				nxt[i]=j;
			}
			for(int i=1,j=0;i<=m2;i++){
				while(j>0&&(j==n2[k]||t2[i]!=s2[k][j+1])) j=nxt[j];
				if(t2[i]==s2[k][j+1]) j++;
				f[i]=j;
				if(f[i]==n1[k]) sum2++,v2=i;
			}
			if(sum2!=1) continue;
			if(v1==v2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
