#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100001][4],ss,s1,s2,s3,x[100001];
char ch;
void R(long long &i){
	for(ch=getchar();ch>'9'||ch<'0';ch=getchar());
	for(i=0;ch>='0'&&ch<='9';ch=getchar())i=i*10+ch-'0';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(;t;t--){
		cin>>n;
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)R(a[i][j]);
		ss=0;
		s1=s2=s3=0;
		memset(x,0,sizeof x);
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])s1++;
			else if(a[i][2]>a[i][1]&&a[i][2]>=a[i][3])s2++;
			else s3++;
		}
		if(s1<=n/2&&s2<=n/2&&s3<=n/2){
			for(int i=1;i<=n;i++)ss+=max(a[i][1],max(a[i][2],a[i][3]));
			cout<<ss<<'\n';
			continue;
		}
		if(s1>n/2){
			for(int i=1;i<=n;i++){
				ss+=max(a[i][1],max(a[i][2],a[i][3]));
				if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])x[++x[0]]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			}
			sort(x+1,x+1+x[0]);
			for(int i=1;i<=s1-n/2;i++)ss-=x[i];
			cout<<ss<<'\n';
			continue;
		}
		if(s2>n/2){
			for(int i=1;i<=n;i++){
				ss+=max(a[i][1],max(a[i][2],a[i][3]));
				if(a[i][2]>a[i][1]&&a[i][2]>=a[i][3])x[++x[0]]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			}
			sort(x+1,x+1+x[0]);
			for(int i=1;i<=s2-n/2;i++)ss-=x[i];
			cout<<ss<<'\n';
			continue;
		}
		if(s3>n/2){
			for(int i=1;i<=n;i++){
				ss+=max(a[i][1],max(a[i][2],a[i][3]));
				if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])x[++x[0]]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
			}
			sort(x+1,x+1+x[0]);
			for(int i=1;i<=s3-n/2;i++)ss-=x[i];
			cout<<ss<<'\n';
			continue;
		}
	}
	return 0;
}

