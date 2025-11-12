#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1[n+1],s2[n+1],t1[q+1],t2[q+1];
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	char s1c[n+1][2100000000]={},s2c[n+1][2100000000]={},s1cm[n+1]={},s2cm[n+1]={};
	char t1c[q+1][2100000000],t2c[q+1][2100000000],t1cm[q+1]={},t2cm[q+1]={};
	for(int i=1;i<=n;i++){
		int aa=0;
		for(int j=0;j<s1[i].size();j++){
			if(aa!=0&&s1[i][j]==s2[i][j]){
				s1cm[i]=1;
				s2cm[i]=1;
				break;
			}
			if(s1[i][j]!=s2[i][j]){
				s1c[i][aa]=s1[i][j];
				s2c[i][aa]=s2[i][j];
				aa++;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		int aa=0;
		for(int j=0;j<t1[i].size();j++){
			if(t1[i][j]!=t2[i][j]){
				t1c[i][aa]=t1[i][j];
				t2c[i][aa]=t2[i][j];
				aa++;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			int aa=0,mm=0;
			if(s1cm!=0)
				while(s1c[j][aa]!='0'){
					if(s1c[j][aa]!=t1c[i][aa]||s2c[j][aa]!=t2c[i][aa]){
						mm=1;
						break;
					}
				}
			if(mm==0) cnt++;
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}