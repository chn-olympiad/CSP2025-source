#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,i,flag,flag1,sum,cnt,tail,len,a[500010],s[500010];
struct node{
	int x,y;
}b[1000010];
bool cmp(node x,node y){
	if(x.x!=y.x) return x.x<y.x;
	return x.y<y.y;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
		if(a[i]>1) flag1=1;
	}
	if(!flag){
		cout<<n/2;
		return 0;
	}
	if(!flag1){
		if(k==0){
			for(i=1;i<=n;i++){
				if(a[i]==0) sum++;
				if(a[i]==1&&a[i+1]==1) sum++,i++;
			}
			cout<<sum;
		}
		else{
			for(i=1;i<=n;i++)
				if(a[i]==1) sum++;
			cout<<sum;
		}
		return 0;
	}
	s[1]=a[1];
	for(i=2;i<=n;i++) s[i]=s[i-1]^a[i];
	for(len=1;len<=n;len++)
		for(i=1;i<=n-len+1;i++)
			if((s[i+len-1]^s[i-1])==k)
				b[++cnt].x=i,b[cnt].y=i+len-1;
	sort(b+1,b+cnt+1,cmp);
	for(i=1;i<=cnt;i++){
		if(i==1) tail=b[1].y,sum++;
		if(b[i].x>tail) tail=b[i].y,sum++;
	}
	cout<<sum;
}
