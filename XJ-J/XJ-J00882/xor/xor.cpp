#include<bits/stdc++.h>
using namespace std;
struct node{
	int l;
	int r;
}s[1000005];
node m[1000005];
bool cmp(node a,node b){
	if(a.r < b.r){
		return 1;
	}
	else return 0;
}
//a.l<b.l
//a.r-a.l<b.r-b.l
//a.r < b.r
int n,k,sum,o;
long long num;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum=a[i];
		if(sum==k){
			o++;
			s[o].l=i;
			s[o].r=i;
		}
		for(int j=i+1;j<=n;j++){
			sum=sum^a[j];
			if(sum==k){
				o++;
				s[o].l=i;
				s[o].r=j;
			}
		}
	}
	sort(s+1,s+o+1,cmp);
	for(int i=1;i<=o;i++){
		bool flag =1;
		for(int j=1;j<=num;j++){
			if(!(s[i].l>m[j].r)){
				flag=0;
			}
		}
		if(flag){
			num++;
			m[num].l=s[i].l;
			m[num].r=s[i].r;
		}
	}
	cout<<num;
	return 0;
}
