#include<bits/stdc++.h>
using namespace std;
int sum,maxx,n,k,a[1010101],t;
long long jiyi[1010][1010];
struct point{
	int l,r;
}xa[1010101];
bool check(int l,int r){
	if(n<=1000){
		if(jiyi[l][r-1]!=0){
			long long x=jiyi[l][r-1]^a[r];
			jiyi[l][r]=x;
			if(x==k){
				return 1;
			}
			else{
				return 0;
			}
		}
	}
	long long x=a[l];
	for(int i=l+1;i<=r;i++){
		x^=a[i];
	}
	if(n<=1000){
		jiyi[l][r]=x;
	}
	if(x==k){
		return 1;
	}
	else{
		return 0;
	}
}
bool cmp(point p,point q){
	if(p.l<q.l){
		return 1;
	}
	else if(p.l>q.l){
		return 0;
	}
	else{
		if(p.r<q.r){
			return 1;
		}
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(i,j)){
				xa[++t].l=i;
				xa[t].r=j;
			}
		}
	}
	sort(xa+1,xa+t+1,cmp);
	for(int i=1;i<=t;i++){
		cout<<xa[i].l<<" "<<xa[i].r<<endl;
	}
	int step=1;
	while(step<=t){
		int f=1; 
		while(f+step<=t){
			if(xa[step].r>=xa[step+f].l){
				if(xa[step].r>xa[step+f].r){
					sum++;
					step=step+f-1;
					f=1;
   					break;
				}
				else{
					sum++;
					f++;
				}			
			}
			else{
				step=step+f-1;
				f=1;
				break;
			}
		}
		step++;
	}
	cout<<t-sum;
	return 0;
}
