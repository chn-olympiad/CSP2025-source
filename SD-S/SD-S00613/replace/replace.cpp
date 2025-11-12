#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,ans,dis[N];
bool f=true;
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=n;i++){
		int l=0,r=s1[i].size();
		while(r<t1.size()){
			if(t1.substr(l,r)==s1[i]){
				if(t1.replace(l,r,s2[i])==t2)
					ans++;
			}
			l++;
			r++;
		}
	}
	for(int i=1;i<=n;i++)
		dis[i]=abs(s1[i].find('b')-s2[i].find('b'));
	while(q--){
		cin>>t1>>t2;
		int b1,b2;
		for(int i=0;i<t1.size();i++)
			if(t1[i]=='b'){
				b1=i;
				break;
			}
		for(int i=0;i<t2.size();i++)
			if(t2[i]=='b'){
				b2=i;
				break;
			}
		for(int i=1;i<=n;i++)
			if(dis[i]==abs(b1-b2))
				ans++;
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

