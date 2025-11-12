#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,num[4],numw[4][100010];
struct mem{
	long long a[4],s[4];
}mem[100010];
void change(long long w){
	long long c,a1=mem[w].a[1],a2=mem[w].a[2],a3=mem[w].a[3],b1=mem[w].s[1],b2=mem[w].s[2],b3=mem[w].s[3];
	if(b1<b2){
		c=a1;
		a1=a2;
		a2=c;
		c=b1;
		b1=b2;
		b2=c;
	}
	if(b2<b3){
		c=a2;
		a2=a3;
		a3=c;
		c=b2;
		b2=b3;
		b3=c;
	}
	if(b1<b2){
		c=a1;
		a1=a2;
		a2=c;
		c=b1;
		b1=b2;
		b2=c;
	}
	mem[w].a[1]=a1;
	mem[w].a[2]=a2;
	mem[w].a[3]=a3;
}
int yiru(long long w,long long z){
	long long l=0,r=num[z],mid=(l+r)/2;
	while(l<r-1){
		if(mem[numw[z][mid]].s[z]<=mem[w].s[z]){
			l=mid;
		}else{
			r=mid;
		}
		mid=(l+r)/2;
	}
	for(long long i=num[z];i>r;i--){
		numw[z][i]=numw[z][i-1];
	}
	numw[z][r]=w;
	return 0;
}
int quchu(long long w,long long z){
	for(long long i=w;i<=num[z];i++){
		numw[z][i]=numw[z][i+1];
	}
	return 0;
}
int fen(long long w){
	long long m1=mem[w].a[1],m2=mem[w].a[2];
	if(num[m1]<n/2){
		ans+=mem[w].s[m1];
		num[m1]++;
		yiru(w,m1);
	}else{
		long long m3,maxm3=0,cha=0,wm3;
		for(long long i=1;i<=n/2;i++){
			m3=numw[m1][i];
			long long m31=mem[m3].s[m1]+mem[w].s[m2],m32=mem[m3].s[mem[m3].a[2]]+mem[w].s[m1];
			if(m31<m32&&m32-m31>cha){
				maxm3=m3;
				wm3=i;
				cha=m32-m31;
			}
		}
		if(maxm3!=0){
			m3=maxm3;
			ans+=mem[w].s[m1];
			ans-=mem[m3].s[mem[m3].a[1]];
			ans+=mem[m3].s[mem[m3].a[2]];
			num[m1]--;
			quchu(wm3,m1);
			num[m1]++;
			yiru(w,m1);
			num[mem[m3].a[2]]++;
			yiru(m3,mem[m3].a[2]);
		}else{
			ans+=mem[w].s[m2];
			num[m2]++;
			yiru(w,m2);
		}
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++){
		cin>>n;
		for(long long j=1;j<=n;j++){
			cin>>mem[j].s[1]>>mem[j].s[2]>>mem[j].s[3];
			mem[j].a[1]=1;
			mem[j].a[2]=2;
			mem[j].a[3]=3;
			change(j);
		}
		for(long long j=1;j<=n;j++){
			fen(j);
		}
		cout<<ans<<endl;
		ans=num[1]=num[2]=num[3]=0;
	}
	return 0;
}
