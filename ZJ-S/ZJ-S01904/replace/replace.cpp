#include<bits/stdc++.h>
using namespace std;
struct P{
	string s1;
	string s2;
}s[200005];
string t1,t2;
bool cmp(P x,P y){
	if(x.s1.size()>y.s1.size())return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	sort(s,s+n,cmp);
	while(q--){
		cin>>t1>>t2;
		int m1=-1,m2=-1;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]&&m1==-1)m1=i;
			if(t1[t1.size()-i]!=t2[t2.size()-i]&&m2==-1)m2=t1.size()-i;
		}
		int leastlen=m2-m1+1,num=0,front=0;
		for(int i=0;i<n&&s[i].s1.size()>=leastlen;i++){
			 if(s[i].s1.size()<=t1.size())num++;
			 else front++;
		}
		int ans=0;
		for(int i=front;i<num+front;i++){
			for(int j=0;j<=t1.size()-s[i].s1.size();j++){
				if(t1[j]==s[i].s1[0]&&m2-j+1<=s[i].s1.size()){
					int p=0;
					for(int k=1;k<s[i].s1.size();k++){
						if(t1[j+k]!=s[i].s1[k]){
							p=1;
							break;
						}
					}
					if(p==0){
						int p1=0;
						for(int k=0;k<s[i].s2.size();k++){
							if(t2[j+k]!=s[i].s2[k]){
								p1=1;
								break;
							}
						}
						if(p1==0){
							ans++;
							break;
						}
					}
				}
			}
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}
