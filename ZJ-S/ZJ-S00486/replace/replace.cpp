#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;	
string st1[N],st2[N],s1,s2,s3;
int n,q,l[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>st1[i]>>st2[i];
		l[i]=st1[i].length();
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		s3=s1;
		int ans=0;
		for(int k=1;k<=n;k++)
		for(int j=0;j<s1.length();j++){
			s3=s1;
			for(int w=0;w<l[k];w++)if(s1[j+w]!=st1[k][w]){
				break;
			}
			else s3[j+w]=st2[k][w];
			if(s3==s2)ans++;
		}
		printf("%d",ans);
	}
}