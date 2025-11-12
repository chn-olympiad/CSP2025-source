#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200010],s2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		t1=' ';t2=' ';
		cin>>t1>>t2;
		int f=0,ans=0;
		for(int i=1;i<=n;i++){
			if(s1[i]==t1&&s2[i]==t2){
				f=1;
				int l=t1.size(),kg=1,js=-1,je=-1;
				for(int i=0;i<l;i++){
					if(t1[i]!=t2[i]){
						if(js!=-1) je=i;
						else kg=0;
					}
					if(!kg&&js==-1){
						js=i;
					}
				}
				if(je==-1&&js!=-1) je=l-1;
				ans+=min(js,l-je-1);
				break;
			}
		}
		if(!f){
			cout<<0<<"\n";
			continue;
		}
		cout<<ans+1<<"\n";
	}
	return 0;
}

