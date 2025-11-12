#include<bits/stdc++.h>
using namespace std;
int replace(string a,string s1,string s2,string b){
	int p;
	for(p=0;p<a.length();p++)
		if(a[p]!=b[p])
			break;
	for(int i=0;i<a.length()-s1.length()+1;i++){
		int flag1=0;
		if(a[i]==s1[0]){
			int flag=1;
			for(int j=0;j<s1.length();j++){
				if(a[i+j]!=s1[j]){
					flag=0;
					break;
				}
			}
			if(flag==1 && (i+s1.length())>p){
				for(int k=0;k<s2.length();k++){
					a[i+k]=s2[k];	
				}
				flag1=1;
			}
		}
		if(flag1)
			break;
	}
	if(a==b)
		return 1;
	else
		return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s[n][2];
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=0;i<q;i++){
		string a[2];
		cin>>a[0]>>a[1];
		int ans=0;
		if(a[0].length()==a[1].length()){
			for(int j=0;j<n;j++){
				if(replace(a[0],s[j][0],s[j][1],a[1])==1){
					ans++;
				}
				else
					continue;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
