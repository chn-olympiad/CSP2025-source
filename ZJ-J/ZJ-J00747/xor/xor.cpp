#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
struct lr{
	int l,r;
};
lr b[5000010];
bool cmp(lr x,lr y){
	return x.r<y.r;
}
long long n,k,a[N],ans,num=1;
int main(){
	/**/freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		int sum=a[i];
		if(a[i]==k){
			b[num].l=i;
			b[num].r=i;
			num++;
			continue;
		}
		int x=i;
		for(int j=x+1;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				b[num].l=x;
				b[num].r=j;
				num++;
				sum=a[j+1];
				x=j+1;	
			}
		}
	}
	int r=b[1].r;
	sort(b+1,b+num,cmp);
	for(int i=1;i<num;i++){
		if(r<b[i+1].l){
			ans++;
			r=b[i+1].r;
		}	
	}
	cout<<ans+1;
	return 0;
}
