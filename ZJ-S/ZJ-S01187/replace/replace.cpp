#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1,t2;
int main(){
	//t3 maybe is tree but i haven't learnt it
	//555555555 so difficult
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	// bao li chu qi ji!!!!!
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;int ans=0;
		for(int j=1;j<=n;j++){
			int pos=0;
			while(t1.find(s1[j],pos)!=-1){
				string t3=t1;t3.replace(t1.find(s1[j],pos),s1[j].size(),s2[j]);
				if(t3==t2)ans++;
				pos=t1.find(s1[j],pos)+s1[j].size();
			}
		}cout<<ans<<endl;
	}
	return 0;
}

