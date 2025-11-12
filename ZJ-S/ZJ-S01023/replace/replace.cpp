#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int f=1;x=0;char s=getchar();
	while (s<'0'||s>'9'){if (s=='-'){f=-f;}s=getchar();}
	while (s>='0'&&s<='9'){x=(x<<1)+(x<<3)+s-'0';s=getchar();}
	x*=f;
}
const int MAXN=2e5+5;
string s[MAXN][2];
int l[MAXN][2];
int n,q,ans;
int work(string a,string b,string x,string y){
	int n=a.length(),m=x.length(),tot=0;
	for (int i=0;i<m-n+1;i++){
		bool flag=true;
		int cnt=i;
		for (int j=0;j<i;j++){
			if (x[j]!=y[j]){
				flag=false;
			}
		}
		if (!flag) break;
		for (int j=0;j<n;j++){
			if (x[cnt]!=a[j]||y[cnt]!=b[j]){
				flag=false;
				break;
			}
			cnt++;
		}
		if (!flag) continue;
		if (flag){
			for (int j=i+n;j<m;j++){
				if (x[j]!=y[j]){
					flag=false;
					break;
				}
			}
			if (flag) tot++;
		}
	}
	return tot;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);read(q);
	for (int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for (int i=1;i<=n;i++){
		int n1=s[i][0].length(),n2=s[i][1].length();
		l[i][0]=n1;l[i][1]=n2;
	}
	for (int i=1;i<=q;i++){
		string a,b;
		int ans=0;
		cin>>a>>b;
		int m=a.length();
		if (m!=b.length()){
			printf("%d\n",0);
			continue;
		}
		for (int j=1;j<=n;j++) ans+=work(s[j][0],s[j][1],a,b);
		printf("%d\n",ans);
	}
	
	return 0;
}

