#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,q;
char w[5000100];
string a[200010],b[200010];
int len[200010];
char x[1000100],y[1000100];
int cnt;
bool p;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		scanf("%s",w+1);
		len[i]=strlen(w+1);
		for(int j=1;j<=len[i];j++) a[i]=a[i]+w[j];
		scanf("%s",w+1);
		for(int j=1;j<=len[i];j++) b[i]=b[i]+w[j];
//		for(int j=0;j<len[i];j++){
//			if(a[i][j]!='a'&&a[i][j]!='b') p=1;
//			if(b[i][j]!='a'&&b[i][j]!='b') p=1;
//		}
	}
//	if(!p){
//		
//		return 0;
//	}
	while(q--){
		scanf("%s",x+1);scanf("%s",y+1);
		if((int)strlen(x+1)!=(int)strlen(y+1)){
			printf("0\n");
			continue;
		}
		cnt=strlen(x+1);
		int ans=0;
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=n;j++){
				bool ppp=1;
				if(i+len[j]-1>cnt) continue;
				for(int l=i;l<=i+len[j]-1;l++){
					if(a[j][l-i]!=x[l]){
						ppp=0;
						break;
					}
					if(b[j][l-i]!=y[l]){
						ppp=0;
						break;
					}
				}
				for(int l=1;l<i;l++){
					if(x[l]!=y[l]){
						ppp=0;
						break;
					}
				}
				for(int l=i+len[j]-1;l<=cnt;l++){
					if(x[l]!=y[l]){
						ppp=0;
						break;
					}
				}
				if(ppp) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}