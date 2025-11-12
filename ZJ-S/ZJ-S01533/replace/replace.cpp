#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e3+5,base=37;
int n,q,le[N];
string s1[N],s2[N];
ull t1[N],t2[N],T1[N],T2[N],p[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i],le[i]=s1[i].size();
	for(int i=1;i<=n;i++){
		s1[i]='&'+s1[i],s2[i]='&'+s2[i];
		for(int j=1;j<=le[i];j++){
			t1[i]=t1[i]*base+s1[i][j]-'a';
			t2[i]=t2[i]*base+s2[i][j]-'a';
		}
	}
	p[0]=1;
	for(int i=1;i<=2000;i++)p[i]=p[i-1]*base;
	while(q--){
		string l1,l2;
		cin>>l1>>l2;
		int len=l1.size(),ans=0;
		l1='&'+l1;l2='&'+l2;
		int l=1,r=len;
		while(l1[l]==l2[l])l++;
		while(l1[r]==l2[r])r--;
		for(int i=1;i<=len;i++){
			T1[i]=T1[i-1]*base+l1[i]-'a';
			T2[i]=T2[i-1]*base+l2[i]-'a';
		}
		for(int i=1;i<l;i++){
			for(int j=1;j<=n;j++){
				if(i+le[j]-1>n||i+le[j]-1<=r)continue;
				ull L1=T1[i+le[j]-1]-T1[i-1],L2=T2[i+le[j]-1]-T2[i-1];
				if(L1==t1[j]*p[i-1]&&L2==t2[j]*p[i-1])ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

