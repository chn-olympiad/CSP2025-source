#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=25;
int a[N],t[N][M];
void jz10_2(int i,int n){
	int cnt=1;
	if(n==0)
	    t[i][1]=0;
	while(n>0){
		t[i][cnt++]=n%2;
		n/=2;
	}
}
int jz2_10(int t[]){
	int ans=t[1],s=1;
	for(int i=2;i<=21;i++){
		s=1;
		for(int j=1;j<=i-1;j++)
			s*=2;
		ans+=s*t[i];
	}
	return ans;
}
int yh(int i,int j){
	int tt[25];
	for(int p=1;p<=21;p++){
		if(t[i][p]==t[j][p])
			tt[p]=0;
		else
		    tt[p]=1;
	}
	return jz2_10(tt);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	memset(t,0,sizeof t);
	int n,k,an=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		jz10_2(i,a[i]);
	}
	int l=1,r=1;
	while(l<=r&&l>=1&&r<=n){
		if(l==r){
			if(a[l]==k){
				l++;r++;
				an++;
			}
			else
			    r++;
		}
		else{
	        int x=a[l];
			for(int i=l+1;i<=r;i++)
				x=yh(x,a[i]);
			if(x==k){
				l=r+1;r=l;
				an++;
			}
			else
			    r++;
		}
	}
	cout<<an;
	return 0;
}
