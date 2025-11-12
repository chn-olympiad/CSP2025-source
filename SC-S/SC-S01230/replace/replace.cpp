#include <bits/stdc++.h>
using namespace std;

const int N=4e5+5,M=1e7+7;
int n,q,L1,L2,num[N],add[M];
string s1[N],s2[N],t1[N],t2[N];
map<string,vector<pair<string,int> > > f;
map<string,vector<int> > f1,f2;

inline void solve(){
	
	for(int i=1;i<=n;i++){
		int len=s1[i].size(),num1=0,num2=0;
		for(int j=0;j<len;j++)
			if(s1[i][j]=='a') num1++;
			else break;
		len=s2[i].size();
		for(int j=0;j<len;j++)
			if(s2[i][j]=='a') num2++;
			else break;
		add[num2-num1+(int)5e6]++;
	}
	
	for(int i=1;i<=q;i++){
		int len=t1[i].size(),num1=0,num2=0;
		for(int j=0;j<len;j++)
			if(t1[i][j]=='a') num1++;
			else break;
		len=t2[i].size();
		for(int j=0;j<len;j++)
			if(t2[i][j]=='a') num2++;
			else break;
		int tot=num2-num1+5e6;
		printf("%d\n",add[tot]);
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i],L1+=(int)s1[i].size(),(int)s2[i].size();
	for(int i=1;i<=q;i++)
		cin>>t1[i]>>t2[i],L2+=(int)t1[i].size()+(int)t2[i].size();
	bool ok=true;
	for(int i=1;i<=n;i++){
		int len=s1[i].size();
		for(int j=0;j<len;j++)
			if(s1[i][j]!='a'&&s1[i][j]!='b') ok=false;
		len=s2[i].size();
		for(int j=0;j<len;j++)
			if(s2[i][j]!='a'&&s2[i][j]!='b') ok=false;		
	}
	for(int i=1;i<=q;i++){
		int len=t1[i].size();
		for(int j=0;j<len;j++)
			if(t1[i][j]!='a'&&t1[i][j]!='b') ok=false;
		len=t2[i].size();
		for(int j=0;j<len;j++)
			if(t2[i][j]!='a'&&t2[i][j]!='b') ok=false;		
	}
	if(ok){
		solve();
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		int len=s1[i].size(),l=-1,r=-1;
		string g,g1,g2,g3;
		g.clear(),g1.clear(),g2.clear(),g3.clear();
		for(int j=0;j<len;j++)
			if(s1[i][j]!=s2[i][j]) r=j;
		for(int j=len-1;j>=0;j--)
			if(s1[i][j]!=s2[i][j]) l=j;
		for(int j=l;j<=r;j++)
			g+=s1[i][j];
		for(int j=l;j<=r;j++)
			g3+=s2[i][j];			
		for(int j=0;j<l;j++)
			g1+=s1[i][j];
		for(int j=r+1;j<len;j++)
			g2+=s1[i][j];
		f[g].push_back({g3,i});
		f1[g1].push_back(i);
		f2[g2].push_back(i);
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++)
			num[j]=0;
		if(t1[i].size()!=t2[i].size()){
			puts("0");
			continue;
		}
		int len=t1[i].size(),l=-1,r=-1;
		string g,g1,g2,g3;
		g.clear(),g1.clear(),g2.clear(),g3.clear();
		for(int j=0;j<len;j++)
			if(t1[i][j]!=t2[i][j]) r=j;
		for(int j=len-1;j>=0;j--)
			if(t1[i][j]!=t2[i][j]) l=j;
		for(int j=l;j<=r;j++)
			g+=t1[i][j];
		for(int j=l;j<=r;j++)
			g3+=t2[i][j];			
		for(int j=0;j<l;j++)
			g1+=t1[i][j];
		for(int j=r+1;j<len;j++)
			g2+=t1[i][j];
		for(auto j:f[g])
			if(j.first==g3)
				num[j.second]++;
		for(auto j:f1[g1])
			num[j]++;	
		for(auto j:f2[g2])
			num[j]++;
		for(int j=1;j<=n;j++)
			ans+=(num[j]==3);
		printf("%d\n",ans);
	}
	return 0;	
}