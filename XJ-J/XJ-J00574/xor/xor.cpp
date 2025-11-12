#include<bits/stdc++.h>
using namespace std;
string s[500050];
long long n,ka,a[500050],j,ans=0;
bool pd(int a,int b){
	string ans;
	int sum=0,maxn=0,ansn=0;
	for(int i=a;i<=b;i++) if(maxn<s[i][0]) maxn=s[i][0];
	for(int k=1;k<=maxn;k++){
		sum=0;
		for(int i=a;i<=b;i++){
			if(s[i][0]>=k){
				if(s[i][k]=='1') sum++;
			}
		}
		if(sum%2==1) ans[k]='1';
		else ans[k]='0';
	}
	for(int k=0;k<maxn;k++){
		if(ans[k+1]=='1'){
			ansn+=2^k;
		}
	}
	if(ansn==ka) return true;
	else return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&ka);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		j=0;
		while(a[i]>0){
			j++;
			s[i][j]=(a[i]%2)+48;
			a[i]/=2;
		}
		s[i][0]=j+48;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(pd(i,j)){
				ans++;
				i=j;
				continue;
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
