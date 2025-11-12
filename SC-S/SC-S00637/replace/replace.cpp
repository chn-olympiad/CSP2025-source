#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int ret=0,op=1;char in=getchar();
	while(!isdigit(in)){if(in=='-'){op=-1;}in=getchar();}
	while(isdigit(in)){ret=(ret<<3)+(ret<<1)+(in^48);in=getchar();}
	return ret*op;
}
int knum,proc;
string val[200010][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	knum=read();proc=read();
	for(int i=1;i<=knum;i+=1){
		cin>>val[i][0]>>val[i][1];
		val[i][0]="-"+val[i][0];
		val[i][1]="-"+val[i][1];
	}
	for(int t=1;t<=proc;t+=1){
		string str1,str2;
		cin>>str1>>str2;
		str1="-"+str1;
		str2="-"+str2;
		if(str1.size()!=str2.size()){
			printf("0\n");
			continue;
		}
		int tot=0;
		for(int i=1;i<=knum;i+=1){
			for(int j=1;j<str1.size()-val[i][0].size()+2;j+=1){
				int flg=1;
				for(int p=1;p<val[i][0].size();p+=1){
					if(p+j-1>=str1.size()){
						flg=0;break;
					}
					if(str1[j+p-1]!=val[i][0][p] or str2[j+p-1]!=val[i][1][p]){
						flg=0;break;
					}
				}for(int p=j+val[i][0].size()-1;p<str1.size();p+=1){
					if(str1[p]!=str2[p]){
						flg=0;break;
					}
				}tot+=flg;
				if(str1[j]!=str2[j])break;
			}
		}
		printf("%lld\n",tot);
	}
	return 0;
}