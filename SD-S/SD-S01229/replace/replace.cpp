#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2;
}s[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	//scanf("%d%d",&n,&q);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		//scanf("%s%s",&s[i].s1,&s[i].s2);
		cin>>s[i].s1>>s[i].s2;
	}
	string t1,t2;
	int tl,tr;
	string dif1,dif2;
	int ans;
	while(q--){
		//scanf("%d%d",&t1,&t2);
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
		}
		else{
			tl=5000001;
			tr=-1;
			for(int i=0;i<t1.size();i++){
				if(t1[i]!=t2[i]){
					tl=min(tl,i);
					tr=max(tr,i); 
				}
			}
			ans=0;
			if(tr==-1&&tl==5000001){
				for(int i=1;i<=n;i++){
					if(s[i].s1==t1&&s[i].s2==t2){
						ans++;
					}
				}
				//printf("%d\n",ans);
				cout<<ans<<"\n";
			}
			else{
				dif1="";
				dif2="";
				for(int i=tl;i<=tr;i++){
					dif1+=t1[i];
					dif2+=t2[i];
				}
				for(int i=1;i<=n;i++){
					if(s[i].s1.size()<dif1.size()){
						continue;
					}
					for(int j=0;j<s[i].s1.size();j++){
						if(s[i].s1[j]==dif1[0]&&s[i].s2[j]==dif2[0]){
							bool flag=true;
							for(int k=j;k<j+dif1.size();k++){
								if(dif1[k-j]!=s[i].s1[k]||dif2[k-j]!=s[i].s2[k]){
									flag=false;
									break;
								}
							}
							if(flag==true){
								ans++;
								break;
							}
						}
					}
				}
				//printf("%d\n",ans);
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}

