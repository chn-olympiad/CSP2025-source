#include<bits/stdc++.h>
using namespace std;
const int base=31,p=9999971;
int n,q;
vector<long long>d1,d2;
char str[5000005],str2[5000005];
long long b[5000001];
map<pair<int,int>,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	b[0]=1;
	for(int i=1;i<=5000000;i++)b[i]=b[i-1]*base%p;
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		int l=strlen(str+1);
		long long sum1=0,sum2=0;
		for(int j=1;j<=l;j++)sum1=(sum1*base%p+str[j]-'a'+1)%p;
		scanf("%s",str+1);
		l=strlen(str+1);
		for(int j=1;j<=l;j++)sum2=(sum2*base%p+str[j]-'a'+1)%p;
		mp[{sum1,sum2}]++;
	}
	for(int i=1;i<=q;i++){
		scanf("%s",str+1);
		int l1=strlen(str+1);
		d1.clear();
		d1.resize(l1+2);
		d1[0]=0;
		for(int j=1;j<=l1;j++)d1[j]=(d1[j-1]*base%p+str[j]-'a'+1)%p;
		scanf("%s",str2+1);
		int l2=strlen(str2+1);
		if(l1!=l2){
			printf("0\n");
			continue;
		}
		d2.clear();
		d2.resize(l2+2);
		d2[0]=0;
		for(int j=1;j<=l2;j++)d2[j]=(d2[j-1]*base%p+str2[j]-'a'+1)%p;
		int sl=0,sr=0;
		for(int j=1;j<=l1;j++)
			if(str[j]!=str2[j]){
				sl=j;
				break;
			}
		for(int j=l1;j>=1;j--)
			if(str[j]!=str2[j]){
				sr=j;
				break;
			}
		long long ans=0;
		for(int j=1;j<=sl;j++)
			for(int k=sr;k<=l1;k++)
				ans+=mp[{(d1[k]-d1[j-1]*b[k-j+1]%p+p)%p,(d2[k]-d2[j-1]*b[k-j+1]%p+p)%p}];
		printf("%lld\n",ans);
	}
	return 0;
}
