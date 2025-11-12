#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,q,cha[200010];
string s1,s2,l1,l2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int len1=s1.size();
		int len2=s2.size();
		int ob,tb;
		for(int j=0;j<len1;j++){
			if(s1[j]=='b'){
				ob=j;
				break;
			}
		}
		for(int j=0;j<len2;j++){
			if(s2[j]=='b'){
				tb=j;
				break;
			}
		}
		cha[i]=ob-tb;
	} 
	while(q--){
		cin>>l1>>l2;
		int len1=l1.size();
		int len2=l2.size();
		if(len1!=len2){
			cout<<0<<endl;
		}else{
			int temp1,temp2;
			for(int i=0;i<len1;i++){
				if(l1[i]=='b'){
					temp1=i;
					break;
				}
			}
			for(int i=0;i<len2;i++){
				if(l2[i]=='b'){
					temp2=i;
					break;
				}
			}
			int chazhi=temp1-temp2,cnt=0;
			for(int i=1;i<=n;i++){
				if(chazhi%cha[i]==0){
					cnt++;
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
} 
