#include<bits/stdc++.h>
using namespace std;
struct Ex_Change{
	string x,y;
}s[200005];
struct sub_b{
	int pre,nxt;
}ch[200005][2];
int KMP[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m,sub_B=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>s[i].x>>s[i].y;
		int xflag=0,yflag=0;
		for(int j=0;j<s[i].x.size();j++){
			
			if(s[i].x[j]=='b') xflag++;
			else if(s[i].x[j]!='a'){
				sub_B=0;
				break;
			}
			else{
				if(!xflag) ch[i][0].pre++;
				else ch[i][0].nxt++;
			}
			if(s[i].y[j]=='b') yflag++;
			else if(s[i].y[j]!='a'){
				sub_B=0;
				break;
			}
			else{
				if(!yflag) ch[i][1].pre++;
				else ch[i][1].nxt++;
			}
			
		}
		if(xflag!=1||yflag!=1) sub_B=0;
	}
	if(m==1){
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){
			puts("0");
			return 0;
		}
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				int ans=0;
				for(int j=1;j<=n;j++){
					for(int k=0;k<s[j].x.size();k++){
						if(s[j].x[k]==x[i]&&s[j].y[k]==y[i]){
							for(int l=i-k;l<i-k+s[j].x.size();l++){
								if(s[j].x[l-i+k]!=x[l]||s[j].y[l-i+k]!=y[l]) break;
								if(l==i-k+s[j].x.size()-1) ans++;
							}
						}
					}
				}
				printf("%d\n",ans);
				return 0;
			}
		}
		return 0;
	}
	if(n>1000){
		for(int i=1;i<=m;i++) puts("0");
		return 0;
	}
	while(m--){
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){
			puts("0");
			continue;
		}
		int ans=0,flag=1,xflag=0,yflag=0;
		int xpre=0,xnxt=0,ypre=0,ynxt=0;
		for(int i=0;i<x.size();i++){
			if(x[i]=='b') xflag++;
			else if(x[i]!='a'){
				flag=0;
				break;
			}
			else{
				if(!xflag) xpre++;
				else xnxt++;
			}
			if(y[i]=='b') yflag++;
			else if(y[i]!='a'){
				flag=0;
				break;
			}
			else{
				if(!yflag) ypre++;
				else ynxt++;
			}
		}
		if(flag&&sub_B){
			int ans=0;
			for(int i=1;i<=n;i++)
				if(xpre>=ch[i][0].pre&&xnxt>=ch[i][0].nxt&&ypre>=ch[i][1].pre&&ynxt>=ch[i][1].nxt&&xpre-ypre==ch[i][0].pre-ch[i][1].pre) ans++;
			printf("%d\n",ans);
			continue;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j+s[i].x.size()<=x.size();j++){
					if(x[j]==s[i].x[0]){
						for(int k=0;k<s[i].x.size();k++){
							if(x[k+j]!=s[i].x[k]||y[k+j]!=s[i].y[k]) goto abc;
						}
						for(int k=j+s[i].x.size();k<x.size();k++) if(x[k]!=y[k]) goto abc;
						ans++;
					}
					else if(x[j]!=y[j]) goto abc;
				}
				abc:
					;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}