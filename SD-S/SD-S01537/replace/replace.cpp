#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 200005
string s1[maxn],s2[maxn];
int n,q,m,ans;
string q1,q2;
int len[maxn];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
	}
	while(q--){
		ans=0;
		cin>>q1>>q2;
		if(q1.size()!=q2.size()){
			printf("0\n");
			continue;
		}
		m=q1.size();
		int flag1,flag2;
		for(int j=0;j<m;j++){
			if(q1[j]!=q2[j]){
				flag1=j;
				break;
			}
		}
		for(int j=m-1;j>=0;j--){
			if(q1[j]!=q2[j]){
				flag2=j;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(flag2-flag1+1>len[i]){
//				cout<<"*****"<<endl;
				continue;
			}
			for(int j=max((long long)0,flag2-len[i]+1);j<=flag1;j++){
//				cout<<j<<endl;
				int flag=0;
				for(int k=j;k<=j+len[i]-1;k++){
					if(q1[k]!=s1[i][k-j]){
						flag=1;
						break;
					}
				}
				if(flag){
					continue;
				}
				string q3=q1;
				for(int k=j;k<=j+len[i]-1;k++){
					q3[k]=s2[i][k-j];
				}
				if(q3==q2){
					ans++;
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
