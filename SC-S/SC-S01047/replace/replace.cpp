#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+10;
int n,q;
long long a[N][3][52],b[N][3][52],c[N][3],d[N][3];
int main(){
	freopen("replace.cpp.in", "r", stdin);
	freopen("replace.cpp.out", "w", stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		char s1[N],s2[N];
		cin>>s1>>s2;
		int len1=strlen(s1),len2=strlen(s2);
		while(len1--){
			int t=s1[len1]-'A'+1;
			a[i][1][t]++;
			c[i][1]++;
		}
		while(len2--){
			int t=s2[len1]-'A'+1;
			a[i][2][t]++;
			c[i][2]++;
		}
	}
	for(int i=1;i<=q;i++){
		char s1[N],s2[N];
		cin>>s1>>s2;
		int len1=strlen(s1),len2=strlen(s2);
		while(len1--){
			int t=s1[len1]-'A'+1;
			b[i][1][t]++;
			d[i][1]++;
		}
		while(len2--){
			int t=s2[len1]-'A'+1;
			b[i][2][t]++;
			d[i][2]++;
		}
	}
	for(int i=1;i<=q;i++){
		bool flag=false;
		if(c[i][1]!=d[i][1] || c[i][2]!=d[i][2]){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=52;j++){
			if(a[i][1][j]!=b[i][1][j]){
				flag=true;
				break;
			}
			else if(a[i][2][j]!=b[i][2][j]){
				flag=true;
				break;
			}
		}
		if(flag==true){
			cout<<0<<endl;
		}
		else{
			cout<<2<<endl;
		}
	}
	return 0;
}