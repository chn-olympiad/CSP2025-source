#include<bits/stdc++.h>
using namespace std;
const int MAXN=200000+5;
const int inf=2147483647;
//
int n,q;
struct node{
	string yuan;
	string repalce;
}a[MAXN],b[MAXN];
//
//
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		string s1,s2;
		cin>>s1>>s2;
		a[i].yuan=s1;
		a[i].repalce=s2;
	}
	for(int i=1;i<=q;++i){
		string s1,s2,s3="";
		int ans=0;
		cin>>s1>>s2;
		b[i].yuan=s1;
		b[i].repalce=s2;
		int len=s2.size();
		for(int k=1;k<=n;++k){
			bool f=1,f1=1;
			s3=b[i].yuan;
			int w=0,l=0,r=0;
			for(int j=0;j<len;++j){
				if(a[k].repalce[w]==b[i].repalce[j]&&a[k].yuan[w]==b[i].yuan[j]){  
					if(f1==1){
						l=j;
						f1=0;
					}
					w++;
				}
			}
			if(w==a[k].repalce.size()){
				r=l+a[k].repalce.size()-1;
				f=0;
			}
			if(f==0){
				for(int j=l;j<=r;++j){
					s3[j]=a[k].repalce[j-l];
				}
				if(s3==b[i].repalce)ans++;
			}
		}
		printf("%d\n",ans);
	}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
	return 0;
}