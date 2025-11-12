#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)	write(x/10);
	putchar(x%10+'0');
	return ;
}
struct node{
	int a,b,c;
};
struct Node{
	int sum,id;
};
const int N=1e5+10;
node s[N];
int w[10],cnt1,cnt2,cnt3;
int num[5][N],n;
int k[N];
bool cmp(node x,node y){
	return max(max(x.a,x.b),x.c)<max(max(y.a,y.b),y.c);
}
int findrr(int x,int y,int z){
	w[1]=x;
	w[2]=y;
	w[3]=z;
	sort(w+1,w+4);
	int s=w[3];
	if(s==z)	return 3;
	if(s==y)	return 2;
	else	return 1;
}
bool cmp2(int x,int y){
	return x>y;
}
int sum;
void wan(int f){
	if(f==1){
		for(int i=0;i<cnt1;i++){
			int x=num[1][i];
			k[i]=max(s[x].c,s[x].b)-s[x].a;
		}
		sort(k,k+cnt1,cmp2);
		int f=cnt1,maxx=0;
		for(int i=0;i<cnt1;i++){
			sum+=k[i];
			f--;
			if(f<=n/2)	maxx=max(maxx,sum);
		}
		write(maxx);
		putchar('\n');
	}
	if(f==2){
		for(int i=0;i<cnt2;i++){
			int x=num[2][i];
			k[i]=max(s[x].a,s[x].c)-s[x].b;
		}
		sort(k,k+cnt2,cmp2);
		int f=cnt2,maxx=0;
		for(int i=0;i<cnt2;i++){
			sum+=k[i];
			f--;
			if(f<=n/2)	maxx=max(maxx,sum);
		}
		write(maxx);
		putchar('\n');
	}
	if(f==3){
		for(int i=0;i<cnt3;i++){
			int x=num[3][i];
			k[i]=max(s[x].a,s[x].b)-s[x].c;
		}
		sort(k,k+cnt3,cmp2);
		int f=cnt3,maxx=0;
		for(int i=0;i<cnt3;i++){
			sum+=k[i];
			f--;
			if(f<=n/2)	maxx=max(maxx,sum);
		}
		write(maxx);
		putchar('\n');
	}
	return ;
}
void print(){
	int ans=0;
	for(int i=0;i<cnt1;i++){
		int id=num[1][i];
		ans+=s[id].a;
	}
	for(int i=0;i<cnt2;i++){
		int id=num[2][i];
		ans+=s[id].b;
	}
	for(int i=0;i<cnt3;i++){
		int id=num[3][i];
		ans+=s[id].c;
	}
	sum=ans;
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		sum=0;
		n=read();
		for(int i=1;i<=n;i++){
			s[i].a=read();
			s[i].b=read();
			s[i].c=read();
		}
		sort(s+1,s+n+1,cmp);
		cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			int pos=findrr(s[i].a,s[i].b,s[i].c);
			if(pos==1)	num[1][cnt1++]=i;
			else if(pos==2)	num[2][cnt2++]=i;
			else if(pos==3)	num[3][cnt3++]=i;
		}
		print();
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			write(sum);
			putchar('\n');
		}
		else{
			if(cnt1>n/2)	wan(1);
			else if(cnt2>n/2)	wan(2);
			else if(cnt3>n/2)	wan(3);
		}
	}
	return 0;
}

