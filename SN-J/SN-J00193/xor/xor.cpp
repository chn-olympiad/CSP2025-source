#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum;
struct s{
	int x,y;
}b[100000000];
bool cmp(s r,s t){
	if(r.x==t.x){
		return r.y<t.y;
	}else{
		return r.x<t.x;
	}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ss=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int flag=a[j];
			for(int k1=j+1;k1<=i+j;k1++){
				flag^=a[k1];
			}
			if(flag==k){
				b[ss].x=j;
				b[ss].y=j+i;
				ss++;
			}
		}
	}
	int flag=0,flid;
	for(int i=1;i<=ss;i++){
		if(!flag){
			flag=b[i].x;
			flid=i;
		}else{
			if(b[i+1].x!=flag){
				sum++;
				flag=0;
			}
		}
	}
	cout<<sum;
	return 0;
}
