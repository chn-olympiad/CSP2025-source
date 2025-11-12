#include<bits/stdc++.h>
using namespace std;
int n,q;
char s1[10004][5004],s2[10004][5004],t1[10004],t2[10004];
int nex[10004];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int t=strlen(t1);
		int ans=0;
		for(int j=1;j<=n;j++){
			int s=strlen(s1[j]);
			for(int k=1;k<=s;k++){
				for(int l=k;l;l=nex[l+1]){
					if(s1[j][nex[l]]==s1[j][l]){
						nex[k+1]=nex[l]+1;
						break;
					}
				}
			}
			int l=1;
			for(int k=1;k<=t;k++){
				while(s1[j][l]==t1[k]&&l<s){
					l++,k++;
				}
				if(l==s){
					bool flag=1;
					int x=k-s+1;
					for(int m=1;m<=t;m++){
						cout<<m<<endl;
						if(x<=m&&m<=x+s-1){
							if(t2[m]!=s2[j][m-x+1]){
								flag=0;
							}
							continue;
						}
						cout<<t2[m]<<" "<<t1[m]<<endl;
						if(t2[m]!=t1[m]){
							flag=0;
						}
					}
					if(flag){
						ans++;
					}
				}
				l=nex[l];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
/*
1 1
ab cd
abacaba cdacaba
*/
/*
*/
