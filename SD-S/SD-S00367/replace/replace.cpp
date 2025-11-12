#include<bits/stdc++.h>
using namespace std;
int n,q,l[200001],awa,ans;
char s1[10001][50001],s2[10001][50001];
string t1,t2,s,t3;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n>10000){
		cin>>s;
		cin>>s;
		for(int i=0;i<q;i++){
			cin>>t1>>t2;
			cout<<n<<endl;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>s;
		l[i]=s.size();
		if(l[i]>50000){
			cin>>s;
			continue;
		}
		for(int j=0;j<s.size();j++){
			s1[i][j]=s[j];
		}
		cin>>s;
		for(int j=0;j<s.size();j++){
			s2[i][j]=s[j];
		}
	}
	for(int i=0;i<q;i++){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<=t1.size();j++){
			for(int k=0;k<n;k++){
				if(t1[j]==s1[k][0]){
					awa=0;
					for(int p=1;p<l[k];p++){
						if(t1[j+p]!=s1[k][p]){
							awa=1;
							break;
						}
					}
					if(!awa){
						t3="";
						for(int p=0;p<j;p++){
							t3=t3+t1[p];
						}
						for(int p=0;p<l[k];p++){
							t3=t3+s2[k][p];
						}
						for(int p=j+l[k];p<t1.size();p++){
							t3=t3+t1[p];
						}
						awa=0;
						for(int p=0;p<=t2.size();p++){
							if(t2[p]!=t3[p]){
								awa=1;
								break;
							}
						}
						if(!awa){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
