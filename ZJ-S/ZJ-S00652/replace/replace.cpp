#include<bits/stdc++.h>
#define int long long

const int N=200010;

using namespace std;

int n,q;

string s1[N],s2[N];

string t1,t2;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+(ch&15),ch=getchar();
	return ret*f;
}

int qry(){
	int ret=0;
	int m=t1.size();
	int l=1e9,r=-1e9;
	
	for(int i=0;i<m;i++)if(t1[i]!=t2[i])l=min(l,i),r=max(r,i);
//	printf("[%lld,%lld]\n",l,r);
	for(int j=1;j<=n;j++){
//		printf("siz=%lld\n",s1[j].size());
		if(s1[j].size()<r-l+1)continue;
		for(int i=0;i<m;i++){
			if(i+s1[j].size()-1>=m)continue;
			int f=1;
			for(int k=0;k<s1[j].size();k++){
				if(t1[i+k]!=s1[j][k]||t2[i+k]!=s2[j][k]){
					f=0;
					break;
				}
			}
			if(f){
//				cout<<j<<endl;
				string t3=t1;
				for(int k=0;k<s1[j].size();k++)t3[i+k]=s2[j][k];
//				cout<<"t3:"<<t3<<' '<<t2<<endl;
				int flg=1;
				for(int k=l;k<=r;k++){
//					printf("%c %c\n",t3[k],t2[k]);
					if(t3[k]!=t2[k]){
						flg=0;
						break;
					}
				}
				if(flg)ret++;
			}
		}
	}
	return ret;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		printf("%lld\n",qry());
	}
	return 0;
}
