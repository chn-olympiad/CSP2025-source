#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=150;
int n,q;
string s1[N],s2[N],t1,t2;
ll ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size();
		if(l1!=l2){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			int l=s1[i].size();
			for(int j=0;j+l-1<l1;j++){
				bool f=true;
				for(int k=0;k<l;k++){
					if(t1[j+k]!=s1[i][k]||t2[j+k]!=s2[i][k]){
						f=false;
						break;
					}
				}
				if(f){
					for(int k=j+l;k<l1;k++){
						if(t1[k]!=t2[k]){
							f=false;
							break;
						}
					}
					if(f){
						ans++;
					}
					if(t1[j]!=t2[j]){
						break;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
