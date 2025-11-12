#include<bits/stdc++.h>
using namespace std;
const int Q=998244353;
const int N=505;
int n,m,c[N],p[N],ans,cnt0;
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	char t=getchar();
	while(t!='1'&&t!='0') t=getchar();
	int ii=1;
	while(t=='1'||t=='0'){
		s[ii]=t; ii++;
		t=getchar();
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		p[i]=i; cnt0+=(c[i]==0);
	}
	if(n<=10){
		do{
			int d=0,cnt=0;
			for(int i=1;i<=n;i++){
//				cout<<p[i]<<" ";
				if(s[i]=='0'||d>=c[p[i]]) d++;
				else cnt++;
			}
//			cout<<cnt<<endl;
			if(cnt>=m) ans++;
		}while(next_permutation(p+1,p+n+1));
		printf("%d",ans);
	}else{
		long long fac=1;
		for(int i=1;i<=n;i++){
			fac=fac*1ll*i%Q;
		}
		printf("%lld",fac);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}