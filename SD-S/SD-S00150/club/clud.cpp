#include<bits/stdc++.h>
using namespace std;
int t,n,b11,b22,b33,s,d[300030],e[300030],f[300030];
struct a{
		int a1,a2,a3;
	int m=0;
};
void dp(int x,int y){
	if(d[x]>=d[y])
	return;
	if(d[x]<d[y]){
		int c;c=d[x];d[x]=d[y];d[y]=c;
		c=e[x];e[x]=e[y];e[y]=c;
		c=f[x];f[x]=f[y];f[y]=c;
		if(x%2==0){
		dp(x/2,x);
		dp(x-1,x);}
		else
		dp(x-1,x);
	}
}
a q[100010];
int main(){
	//freopen("clud.in","r",stdin);
	//freopen("clud.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
	cin>>n;
	b11=0;b22=0;b33=0;s=0;
	for(int j=1;j<=n;j++){
	q[j].m=0;
	cin>>q[j].a1;e[j*3-2]=1;f[j*3-2]=j;d[j*3-2]=-1;
	cin>>q[j].a2;e[j*3-1]=2;f[j*3-1]=j;d[j*3-1]=-1;
	cin>>q[j].a3;e[j*3]=3;f[j*3]=j;d[j*3]=-1;}
	d[0]=20005;
	for(int j=1;j<=n;j++){
		d[j*3-2]=q[j].a1;
		if((j*3-2)%2==0)
		dp((j*3-2)/2,j*3-2);
		else
		dp(j*3-3,j*3-2);
		d[j*3-1]=q[j].a2;
		if((j*3-1)%2==0)
		dp((j*3-1)/2,j*3-1);
		else
		dp(j*3-2,j*3-1);
		d[j*3]=q[j].a3;
		if((j*3)%2==0)
		dp((j*3)/2,j*3);
		else
		dp(j*3-1,j*3);
	}
	for(int j=1;j<=n*3;j++){
		if(e[j]==1&&q[f[j]].m==0){
			if(b11<=n/2-1){
			s+=d[j];b11+=1;q[f[j]].m=1;}
			else{int k=j-1,l=j+1;
			while(e[k]!=1&&k>0)
			k--;
			while(f[l]!=f[j]&&l<=n){
			l++;
			if(f[l]==f[j]){
				if(f[l]==2&&b22>n/2-1){
				l++;}
				
				if(f[l]==3&&b33>n/2-1){
				l++;}
			}
			}
			if(k>0&&l<=n)
			if(s<(s-d[k]+d[l])){
				s=s-d[k]+d[l];
				if(f[l]==2)
				b22++;
				if(f[l]==3)
				b33++;
				
			}
			}
		}
		if(e[j]==2&&q[f[j]].m==0){
			if(b22<=n/2-1){
			s+=d[j];b22+=1;q[f[j]].m=1;}
			else{int k=j-1,l=j+1;
			while(e[k]!=2&&k>0)
			k--;
			while(f[l]!=f[j]&&l<=n){
			l++;
			if(f[l]==f[j]){
				if(f[l]==1&&b11>n/2-1){
				l++;}
				
				if(f[l]==3&&b33>n/2-1){
				l++;}
				
			}
			}
			if(k>0&&l<=n)
			if(s<(s-d[k]+d[l])){
				s=s-d[k]+d[l];
				if(f[l]==2)
				b22++;
				if(f[l]==3)
				b33++;
				
			}
			}
		}if(e[j]==3&&q[f[j]].m==0){
			if(b33<=n/2-1){
			s+=d[j];b33+=1;q[f[j]].m=1;}
			else{int k=j-1,l=j+1;
			while(e[k]!=3&&k>0)
			k--;
			while(f[l]!=f[j]&&l<=n){
			l++;
			if(f[l]==f[j]){
				if(f[l]==1&&b11>n/2-1)
				l++;
				if(f[l]==2&&b22>n/2-1)
				l++;
			}
			}
			if(k>0&&l<=n)
			if(s<(s-d[k]+d[l])){
				s=s-d[k]+d[l];
				if(f[l]==1)
				b11++;
				if(f[l]==2)
				b22++;
				
			}
			}
		}
	}
	cout<<s<<endl;}
	return 0;
}
