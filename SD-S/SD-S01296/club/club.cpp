#include<bits/stdc++.h>
#define int long long
using namespace std;
int ksm(int a,int b,int p){
	int ans=1;
	while(b){
		if(b&1) ans=(ans*a)%p;
		b>>=1;a=(a*a)%p;
	}return ans;
}
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
struct nd{
	int a1,a2,a3;
}a[100005],A1[100005],A2[100005],A3[100005];
bool cmp1(nd aa,nd bb){
	return aa.a1-max(aa.a2,aa.a3)<bb.a1-max(bb.a2,bb.a3);
}
bool cmp2(nd aa,nd bb){
	return aa.a2-max(aa.a1,aa.a3)<bb.a2-max(bb.a1,bb.a3);
}
bool cmp3(nd aa,nd bb){
	return aa.a3-max(aa.a2,aa.a1)<bb.a3-max(bb.a2,bb.a1);
}
void sol(){
	int n=read(),c1=0,c2=0,c3=0,ans1=0,ans2=0,ans3=0;
	for(int i=1;i<=n;i++){
		a[i].a1=read();
		a[i].a2=read();
		a[i].a3=read();
		if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
			ans1+=a[i].a1;
			c1++;
			A1[c1]=a[i];
		}else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){
			ans2+=a[i].a2;
			c2++;
			A2[c2]=a[i];
		}else{
			ans3+=a[i].a3;
			c3++;
			A3[c3]=a[i];
		}
	}
//	cout<<c1<<" "<<c2<<" "<<c3<<"\n";
	if(c1<=n/2&&c2<=n/2&&c3<=n/2){
		cout<<ans1+ans2+ans3<<"\n";
		return;
	}
	if(c1>c2&&c1>c3){
		sort(A1+1,A1+1+c1,cmp1);
		int cj23=1919810,cj32=1919810;
		for(int i=1;i<=n;i++){
			ans1-=A1[i].a1;
			c1--;
			if(A1[i].a2>=A1[i].a3) ans2+=A1[i].a2,c2++,cj23=min(cj23,A1[i].a2-A1[i].a3);
			else ans3+=A1[i].a3,c3++,cj32=min(cj32,A1[i].a3-A1[i].a2);
			if(c1<=n/2) break;
		}
		if(c2>n/2) cout<<ans1+ans2+ans3-cj23<<"\n";
		else if(c3>n/2) cout<<ans1+ans2+ans3-cj32<<"\n";
		else cout<<ans1+ans2+ans3<<"\n";
	}
	else if(c2>c1&&c2>c3){
		int cj13=1919810,cj31=1919810;
		sort(A2+1,A2+1+c2,cmp2);
		for(int i=1;i<=n;i++){
			ans2-=A2[i].a2;
			c2--;
			if(A2[i].a1>=A2[i].a3) ans1+=A2[i].a1,c1++,cj13=min(cj13,A2[i].a1-A2[i].a3);
			else ans3+=A2[i].a3,c3++,cj31=min(cj31,A2[i].a3-A2[i].a1);
			if(c2<=n/2) break;
		}
		if(c1>n/2) cout<<ans1+ans2+ans3-cj13<<"\n";
		else if(c3>n/2) cout<<ans1+ans2+ans3-cj31<<"\n";
		else cout<<ans1+ans2+ans3<<"\n";
	}
	else{
		sort(A3+1,A3+1+c3,cmp3);
		int cj12=1919810,cj21=1919810;
		for(int i=1;i<=n;i++){
			ans3-=A3[i].a3;
			c3--;
			if(A3[i].a1>=A3[i].a2) ans1+=A3[i].a1,c1++,cj12=min(cj12,A3[i].a1-A3[i].a2);
			else ans2+=A3[i].a2,c2++,cj21=min(cj21,A3[i].a2-A3[i].a1);
			if(c3<=n/2) break;
		}
		if(c1>n/2) cout<<ans1+ans2+ans3-cj12<<"\n";
		else if(c2>n/2) cout<<ans1+ans2+ans3-cj21<<"\n";
		else cout<<ans1+ans2+ans3<<"\n";
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	T=read();
	while(T--) sol();
	return 0;
}
