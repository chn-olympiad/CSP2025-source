#include<bits/stdc++.h>
using namespace std;
string yuan[200010],ti[200010],a[200010],b[200010];
int n,q,len[200010],vis[30][200010],visl[30],qian[200010],hou[200010],cha[200010];
//xabcx->xadex  bc->de
bool check(string s,int k,string ss,int x){
//	printf("序号：%d  替换位置：%d\n",k,x);
	//3 2
	for(int i=0;i<=len[k];i++){
		if(yuan[k][i]!=s[i+x]||ti[k][i]!=ss[i+x]) return 0;
	}
	int l=s.size();
	for(int i=len[k]+x+1;i<l;i++){
		if(s[i]!=ss[i]){
//			cout<<i;
			return 0;
		}
	}
	return 1;
}
void teshu(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=len[i];j++){
			if(yuan[i][j]=='b')  qian[i]=j,hou[i]=len[i]-j,cha[i]+=j;
			if(ti[i][j]=='b') cha[i]-=j;
		}
//		printf("%d:前-%d 后-%d 差-%d\n",i,qian[i],hou[i],cha[i]);
	}
	for(int i=1;i<=q;i++){
		string yuanshi=a[i],mubiao=b[i];
		int chaa=0,qiann=0,houu=0,l=a[i].size()-1;
		for(int j=0;j<=l;j++){
			if(yuanshi[j]=='b')  qiann=j,houu=l-j,chaa+=j;
			if(mubiao[j]=='b') chaa-=j;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			if(qian[j]<=qiann&&hou[j]<=houu&&chaa==cha[j]) ans++;
		}
		printf("%d\n",ans);
	}
}
/*
4 5
aab  baa
aba  baa
baaa abaa
aaba abaa

aab baa
aba baa
baaa abaa
aaba abaa
a b

*/
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	scanf("%d%d",&n,&q);
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>yuan[i]>>ti[i];
		len[i]=yuan[i].size()-1;
		vis[yuan[i][0]-'a'][++visl[yuan[i][0]-'a']]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=len[i];j++){
			if(yuan[i][j]!='a'&&yuan[i][j]!='b'){
				flag=1;
				break;
			}
			if(ti[i][j]!='a'&&ti[i][j]!='b'){
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
	
	int l=0;
	for(int i=1;i<=q;i++){
		cin>>a[i]>>b[i];
		l=max(l,int(max(a[i].size(),b[i].size())));
	}
	if(flag==0){
		teshu();
		return 0;
	}
	for(int u=1;u<=q;u++){
		string yuanshi,mubiao;
		yuanshi=a[u],mubiao=b[u];
//		cout<<yuanshi<<' '<<mubiao<<'\n';
		int l=yuanshi.size(),ans=0;
		for(int i=0;i<l;i++){
			if(i>0&&yuanshi[i-1]!=mubiao[i-1]) break;
			if(visl[yuanshi[i]-'a']){
//				cout<<i<<':'<<'\n';
				for(int j=1;j<=visl[yuanshi[i]-'a'];j++){
//					cout<<i<<':'<<vis[yuanshi[i]-'a'][j]<<'\n';
					if(check(yuanshi,vis[yuanshi[i]-'a'][j],mubiao,i)){
//						cout<<"成功"<<'\n';
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}//60pts
