#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define UL unsigned long long
const LL inf=5e7;
int n,q,L[200005],R[200005];
string cf,s[200005][2],c;
UL b[35],a[200005][2],x,y,u;
UL ha(string k,int l,int r){
	UL ans=0;
	for(int i=l;i<=r;i++){
		ans+=b[k[i]-'a'+1]*(i-l+1);
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	for(int i=1;i<=26;i++)b[i]=rand();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int l=-1,r;
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]!=s[i][1][j]){
				if(l==-1)l=j;
				r=j;
			}
		}
		a[i][0]=ha(s[i][0],l,r);
		a[i][1]=ha(s[i][1],l,r);
		L[i]=l;
		R[i]=r;
	}
	for(int i=1;i<=q;i++){
		cin>>c>>cf;
		if(c.size()!=cf.size()||u>=inf){
			printf("0\n");
			continue;
		}
		int l=-1,r;
		for(int j=0;j<c.size();j++){
			if(c[j]!=cf[j]){
				if(l==-1)l=j;
				r=j;
			}
		}
		x=ha(c,l,r);
		y=ha(cf,l,r);
		int sum=0;
		for(int j=1;j<=n;j++){
			if(x!=a[j][0]||y!=a[j][1])continue;
			if(l<L[j]||c.size()-r<s[j][0].size()-R[j])continue;
			int flag=0,tmp=0;
			for(int k=l-L[j];k<l;k++){
				if(c[k]!=s[j][0][tmp]){
					flag=1;
					break;
				}
				tmp++;
				if(u+tmp>inf){
					flag=1;
					break;
				}
			}
			u+=tmp;
			if(flag)continue;
			tmp=R[j]+1;
			for(int k=r+1;tmp<s[j][0].size();k++){
			    if(c[k]!=s[j][0][tmp]){
					flag=1;
					break;
				}
				tmp++;
				if(u+tmp>inf){
					flag=1;
					break;
				}
			}
			u+=tmp;
			if(flag)continue;
			sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
