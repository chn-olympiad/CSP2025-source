#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N];
string s2[N];
string t1;
string t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int x=1;x<=q;x++){
		int ans=0;
		cin>>t1>>t2;
		int len1=t1.size();
		for(int i=0;i<n;i++){
			int len2=s1[i].size();
			for(int j=0;j+len2-1<len1;j++){
				int flag=0;
				for(int k=j;k<=j+len2-1;k++){
					if(t1[k]!=s1[i][k-j]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					string t3=t1;
					for(int l=j;l<=j+len2-1;l++){
						t3[l]=s2[i][l-j];
					}
					int flag2=0;
					for(int l=0;l<len1;l++){
						if(t3[l]!=t2[l]){
							flag2=1;
							break;
						}
					}
					if(flag2==0){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
