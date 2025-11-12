#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,a[500005],s[500005],cnt,mi[500005],cn;
vector<int>mp[1000005];
struct Info{
	int l,r;
	bool use;
}b[500005],c[500005];
bool cmp(Info x,Info y){
	return x.r-x.l>y.r-y.l;
}
bool cmp1(Info x,Info y){
	if(x.l!=y.l)return x.l<y.l;
	return x.r<y.r;
}
bool del[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool canb=1;
	for(int i=1;i<=n;i++){
		c[i].use=0;
		mi[i]=1e9;
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		mp[s[i]].push_back(i);
		if(a[i]>=2){
			canb=0;
		}
	}
	if(canb&&k<=1){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	mp[0].push_back(0);
	for(int i=1;i<=n;i++){
		int tmp=s[i]^k;
		for(auto y:mp[tmp]){
			if(y<i){
				int l=y+1,r=i;
				if(mi[l]>r){
					mi[l]=r;
					cnt++;
					b[cnt].l=l;
					b[cnt].r=r;
				}
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){//TLE
		if(del[i]){
			continue;
		}
		for(int j=i+1;j<=cnt;j++){
			if(i==j){
				continue;
			}
			if(b[j].l<=b[i].l&&b[i].r<=b[j].r){
				del[j]=1;
			}
			if(b[i].l<=b[j].l&&b[j].r<=b[i].r){
				del[i]=1;
			}
			if(del[i]){
				break;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(del[i]==0){
			cn++;
			c[cn]=b[i];
		}
	}
	sort(c+1,c+cn+1,cmp1);
	int ans=0,la=0;
	for(int i=1;i<=cn;i++){
		if(c[la].r<c[i].l){
			ans++;
			la=i;
		}
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
x^y=z
y^z=x

*/