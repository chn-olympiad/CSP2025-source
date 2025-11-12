#include<bits/stdc++.h>
using namespace std;
int n,T,i,la,x,l[200010],sum,t,fl,fll,ans,j;
string a,b,s1[200010],s2[200010],ss;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>T;
	for(i=1;i<=n;i++)cin>>s1[i]>>s2[i],l[i]=s1[i].size();
	while(T--){
		cin>>a>>b;la=a.size();ans=0;
		if(la!=b.size()){
			cout<<"0\n";
			continue;
		}
		for(i=1;i<=n;i++){
			t=0;fl=0;
			while(t<=la-l[i]+1){
				if(a[t]==s1[i][0]){
					fll=0;
					for(j=0;j<l[i];j++)
						if(a[t+j]!=s1[i][j]){
							fll=1;
							break;
						}
					if(!fll){
						fll=0;
						for(j=0;j<l[i];j++)
							if(b[t+j]!=s2[i][j]){
								fll=1;
								break;
							}
						if(!fll){
							fll=0;
							for(j=t+l[i];j<=la;j++)
								if(a[j]!=b[j]){
									fll=1;
									break;
								}
							if(!fll)ans++;
						}
					}
				}
				if(a[t]!=b[t])break;
				t++;
			}
		}
		cout<<ans<<"\n"; 
	}
	return 0;
}