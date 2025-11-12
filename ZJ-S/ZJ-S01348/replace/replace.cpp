#include<bits/stdc++.h>
using namespace std;
int n,q,l1,l2,l,r,ans;
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	while(n--){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		l1=t1.size();
		l2=t2.size();
		if(l1!=l2){
			printf("0\n");
			continue;
		}
		for(int i=0;i<l1;i++){
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		}
		for(int i=l1-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		}
		for(int i=0;i<=l;i++){
			for(int j=r;j<l1;j++){
				int flag=0;
				string s,c;
				s=t1.substr(i,j-i+1);
				if(mp.find(s)==mp.end()){
					continue;
				}
				c=mp[s];
				for(int k=i;k<=j;k++){
					if(c[k-i]!=t2[k]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
