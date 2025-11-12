#include<bits/stdc++.h>
using namespace std;
int n,q;
map<pair<string,string>,int>mp;
map<pair<int,int>,int>M;
int solve(string a,string b){
	int n=a.size();
	a=" "+a;
	b=" "+b;
	int l=1e9,r=0,ret=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			l=min(l,i);
			r=max(r,i);
		}
	}if(l>r){
		l=0;
		r=n+1;
	}
	for(int i=1;i<=l;i++){
		for(int j=r;j<=n;j++){
			string t1=a.substr(i,j-i+1),t2=b.substr(i,j-i+1);
			ret+=mp[{t1,t2}];
		}
	}return ret;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
//	if(q<=100){
		for(int i=1;i<=n;i++){
			string s1,s2;
			cin>>s1>>s2;
			mp[{s1,s2}]++;
		}while(q--){
			string t1,t2;
			cin>>t1>>t2;
			solve(t1,t2);
			printf("%d\n",solve(t1,t2));
		}
//	}else{
//		for(int i=1;i<=n;i++){
//			string s1,s2;
//			cin>>s1>>s2;
//			int cnt1[2]={},cnt2[2]={},op=0;
//			for(int i=0;i<(int)s1.size();i++){
//				if(s1[i]=='b')op++;
//				else{
//					cnt1[op]++;
//				}
//			}op=0;
//			for(int i=0;i<(int)s2.size();i++){
//				if(s2[i]=='b')op++;
//				else{
//					cnt2[op]++;
//				}
//			}M[{cnt1[0]-cnt2[1],(int)s1.size()}]++;
//		}
//		while(q--){
//			int ans=0;
//			string t1,t2;
//			cin>>t1>>t2;
//			int cnt1[2]={},cnt2[2]={},op=0;
//			for(int i=0;i<(int)t1.size();i++){
//				if(t1[i]=='b')op++;
//				else{
//					cnt1[op]++;
//				}
//			}op=0;
//			for(int i=0;i<(int)t2.size();i++){
//				if(t2[i]=='b')op++;
//				else{
//					cnt2[op]++;
//				}
//			}for(int i=1;i<=(int)t1.size();i++){
//				ans+=M[{cnt1[0]-cnt2[1],i}];
//			}
//			printf("%d\n",ans);
//		}
//	}
	
	return 0;
}