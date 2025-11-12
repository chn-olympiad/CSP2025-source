#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int N=2e5+5;
const int M=5e6+5;
int n,q;
vector <PII> vec[N];
struct node{string s1,s2;}a[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	if(n<=10000/q){
		while(q--){
			string s1,s2;
			cin>>s1>>s2;
			if(s1.size()!=s2.size()){printf("0\n");continue;}
			int ll=s1.size()-1,rr=0;
			for(int i=0;i<s1.size();i++)
				if(s1[i]!=s2[i]) ll=min(ll,i),rr=max(rr,i);
			int ans=0;
			for(int i=1;i<=n;i++){
				string x=a[i].s1,y=a[i].s2;
				if(s1.find(x)==-1) continue;
				int l=s1.find(x);
				if(s2.substr(l,x.size())==y&&l<=ll&&l+x.size()-1>=rr) ans++;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int pos1=a[i].s1.find("b");
		int pos2=a[i].s2.find("b");
		vec[pos1-pos2].push_back({pos2,n-pos1});
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int pos1=s1.find("b"),pos2=s2.find("b"),ans=0;
		for(auto i:vec[pos1-pos2])
			if(i.first<=pos2&&i.second<=n-pos1) ans++;
	    printf("%d\n",ans);
	}
	return 0;
}

