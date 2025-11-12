#include<bits/stdc++.h>
using namespace std;

long long n,q,ans,t;
string s1[200005],s2[200005],t1,t2,t3;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
		}else{
			for(int j=0;j<=t1.size()-1;j++){
				for(int k=1;k<=n;k++){
					t=0;
					t3=t1;
					for(int l=0;l<=s1[k].size()-1;l++){
						if(t1[j+l]!=s1[k][l]){
							t=1;
							break;
						}else{
							t3[j+l]=s2[k][l];
						}
					}
					if(t==0&&t2==t3){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 