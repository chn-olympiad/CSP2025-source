#include<bits/stdc++.h>
using namespace std;
struct stu{
	int l,r;
}b[500005];
long long n,k,a,s[500005],m=0,ans;

bool cmp(stu a,stu b){
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		s[i]=s[i-1]^a;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((s[i]^s[j-1])==k){
				b[++m].l=j;
				b[m].r=i;
			}
		}
	}
	if(m==0){
		cout<<0;
		return 0;
	}
	else ans=1;
	sort(b+1,b+m+1,cmp);
	int x=b[1].r;
	for(int i=2;i<=m;i++){
		if(b[i].l>x){
			ans++;
			x=b[i].r;
		}
	}
	cout<<ans;

	return 0;
}
