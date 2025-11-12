#include<iostream>
#include<algorithm>
using namespace std;
int a[500005]={};
struct A{
	int l,r;
}s[100005];
int num=0;
bool cmp(A x,A y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x]=(a[x-1]^x);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[j]^a[i-1])==k){//cout<<i<<" "<<j<<" "<<a[j]<<" "<<a[i-1]<<endl;
				num++;
				s[num].l=i;
				s[num].r=j;
				break;
			}
		}
	}
//	cout<<s[1].l<<" "<<s[1].r<<" "<<s[2].l<<" "<<s[2].r<<" "<<s[3].l<<" "<<s[3].r;
	sort(s+1,s+num+1,cmp);
	long long ans=0,r=0;
	for(int i=1;i<=num;i++){
		if(s[i].l>r){
			r=s[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}// 1 1 1 2 2 4
