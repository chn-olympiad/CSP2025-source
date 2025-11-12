#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int now=0,res=1;char c=getchar();
	while(!isdigit(c))res=(c=='-'?-1:1),c=getchar();
	while(isdigit(c))now=now*10+c-'0',c=getchar();
	return now*res;
}
const int M=2.5e6+10,N=2e5+10;
char s[4][M];
int n,q,tot,mark[N];
int pass[M+10];
struct chtree{
	int tot=0;vector<int>ch[28];
	vector<vector<int>>sum;
	void insert(){for(int i=0;i<26;i++)ch[i].push_back(0);sum.push_back({});}
	void add(char S[],int id){
		int now=0;
		if(!ch[0].size())insert();
//		cout<<S+1<<" "<<strlen(S+1)<<endl;
		for(int i=1;i<=strlen(S+1);i++){
			char v=S[i];
//			cout<<now<<" "<<v<<" ";
//			cout<<ch[v-'a'][now]<<"\n";
			if(ch[v-'a'][now]!=0)now=ch[v-'a'][now];
			else ch[v-'a'][now]=++tot,now=tot,insert();
		}
//		cout<<now<<" "<<id<<endl;
		sum[now].push_back(id);
	}
	vector<int>find(char S[]){
		int now=0;
		vector<int>_find;
		if(strlen(S+1)==0){
//			cout<<"WRAR:";
//			for(auto g:sum[now])cout<<g<<" ";
//			cout<<"\n";
		}
		for(int i=1;i<=strlen(S+1);i++){
			char v=S[i];
//			cout<<now<<" "<<v<<endl;
//			for(auto g:sum[now])cout<<g<<" ";cout<<"\n";
			for(auto g:sum[now])_find.push_back(g);
			if(ch[v-'a'][now])now=ch[v-'a'][now];
			else return _find;
		}
		for(auto g:sum[now])_find.push_back(g);
		return _find;
	}
	int qur(){return ch[0].size();}
};
map<pair<pair<unsigned long long,unsigned long long>,pair<unsigned long long,unsigned long long> >,pair<chtree,chtree> >ma;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		scanf("%s%s",s[0]+1,s[1]+1);
		int len=strlen(s[0]+1);
		int beg=0,en=len+1,sim=0;
		unsigned long long Hs0=0,Hs1=0,Hs2=0,Hs3=0;
		for(int j=1;j<=len;j++)if(beg==j-1&&s[0][j]==s[1][j])beg++;
		for(int j=len;j>=1;j--)if(en==j+1&&s[0][j]==s[1][j])en--;
		if(beg>en)continue;
		int len0=0,len1=0;
		for(int j=beg;j>=1;j--)s[2][++len0]=s[0][j];
		for(int j=en;j<=len;j++)s[3][++len1]=s[0][j];
		for(int j=beg+1;j<en;j++)Hs0=Hs0*131+s[0][j],Hs1=Hs1*131+s[1][j];
		for(int j=beg+1;j<en;j++)Hs2=Hs2*1331+s[0][j],Hs3=Hs3*1331+s[1][j];
//		for(int j=beg+1;j<en;j++)cout<<s[0][j];cout<<"\n";
//		for(int j=beg+1;j<en;j++)cout<<s[1][j];cout<<"\n";
//		cout<<s[3]+1<<"\n";
		ma[{{Hs0,Hs2},{Hs1,Hs3}}].first.add(s[2],i);
		ma[{{Hs0,Hs2},{Hs1,Hs3}}].second.add(s[3],i);
//		cout<<Hs0<<" "<<Hs1<<" "<<endl;
		for(int j=0;j<=len0;j++)s[2][j]=0;
		for(int j=0;j<=len1;j++)s[3][j]=0;
	}
	for(int qq=1;qq<=q;qq++){
		scanf("%s%s",s[0]+1,s[1]+1);
		int len=strlen(s[0]+1);
		int beg=0,en=len+1;
		unsigned long long Hs0=0,Hs1=0,Hs2=0,Hs3=0;
		for(int j=1;j<=len;j++)if(beg==j-1&&s[0][j]==s[1][j])beg++;
		for(int j=len;j>=1;j--)if(en==j+1&&s[0][j]==s[1][j])en--;
		if(beg>en){puts("0");continue;}
		int len0=0,len1=0,ans=0;
		for(int j=100;j>=0;j--)s[2][j]=s[3][j]=0;
		for(int j=beg;j>=1;j--){
			s[2][++len0]=s[0][j];
		}for(int j=en;j<=len;j++)s[3][++len1]=s[0][j];
//		cout<<s[3]+1<<endl;
		for(int j=beg+1;j<en;j++)Hs0=Hs0*131+s[0][j],Hs1=Hs1*131+s[1][j];
		for(int j=beg+1;j<en;j++)Hs2=Hs2*1331+s[0][j],Hs3=Hs3*1331+s[1][j];
//		cout<<Hs0<<" "<<Hs1<<endl;
		
		if(!ma[{{Hs0,Hs2},{Hs1,Hs3}}].first.qur()){puts("0");continue;}
		vector<int>_fi=ma[{{Hs0,Hs2},{Hs1,Hs3}}].first.find(s[2]);
		vector<int>_fi1=ma[{{Hs0,Hs2},{Hs1,Hs3}}].second.find(s[3]);
		for(auto v:_fi){
			mark[v]=qq;
//			cout<<v<<" ";
		}
//		cout<<"\n";
		for(auto v:_fi1){
			ans+=(mark[v]==qq);
//			cout<<v<<" ";
		}
//		cout<<"\n";
		printf("%d\n",ans);
		for(int i=0;i<=len0;i++)s[2][i]=0;
		for(int i=0;i<=len1;i++)s[3][i]=0;
		
	}
	return 0;
}
/*
10 5
a b
c d
*/
