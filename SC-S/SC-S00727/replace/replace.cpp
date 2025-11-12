#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,q,ans;
string s1[N],s2[N],t1,t2,t3;
bool g;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			printf("0\n");
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(s1[i].length()>t1.length())continue;
			for(int j=0;j<=t1.length()-s1[i].length();j++){
				if(t1.substr(j,s1[i].length())==s1[i]){
					t3=t1.substr(0,j)+s2[i]+(j+s1[i].length()>=t1.length()?"":t1.substr(j+s1[i].length(),t1.length()-(j+s1[i].length())));
					if(t3==t2)ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
} 