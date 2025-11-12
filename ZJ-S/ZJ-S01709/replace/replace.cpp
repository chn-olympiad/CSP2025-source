#include"cstdio"
#include"cstring"
const int N=5000010;
int n,q;
int t[N*2][28],z[N*2],cnt;
char a[N],b[N];
int get1(char a[],int l,int r,int now){
	for(int i=l;i<=r;i++){
		if(!t[now][a[i]-'a'+1])t[now][a[i]-'a'+1]=++cnt;
		now=t[now][a[i]-'a'+1];
	}
	return now;
}
int get2(char a[],int l,int r,int now){
	for(int i=r;i>=l;i--){
		if(!t[now][a[i]-'a'+1])t[now][a[i]-'a'+1]=++cnt;
		now=t[now][a[i]-'a'+1];
	}
	return now;
}
void push(){
	int n,dl=-1,dr=-1;
	n=strlen(a);
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			if(dl==-1)dl=i;
			dr=i;
		}
	}
	if(dl==-1)return;
	int now=0;
	now=get1(a,dl,dr,now);
	if(!t[now][0])t[now][0]=++cnt;
	now=t[now][0];
	now=get1(b,dl,dr,now);
	if(!t[now][0])t[now][0]=++cnt;
	now=t[now][0];
	now=get2(a,0,dl-1,now);
	if(!t[now][0])t[now][0]=++cnt;
	now=t[now][0];
	now=get1(a,dr+1,n-1,now);
	z[now]++;
}
int get(char a[],int l,int r,int now){
	for(int i=l;i<=r;i++){
		if(!t[now][a[i]-'a'+1])return 0;
		now=t[now][a[i]-'a'+1];
	}
	return now;
}
int check(){
	int n,m,dl=-1,dr=-1;
	n=strlen(a);m=strlen(b);
	if(n!=m)return 0;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			if(dl==-1)dl=i;
			dr=i;
		}
	}
	int now=0;
	now=get(a,dl,dr,now);
	if(now==0||!t[now][0])return 0;
	now=t[now][0];
	now=get(b,dl,dr,now);
	if(now==0||!t[now][0])return 0;
	now=t[now][0];
	
	int sum=0;
	for(int i=dl;i>=0;i--){
		int nowt=t[now][0];
		for(int j=dr;j<n;j++){
			sum+=z[nowt];
			nowt=t[nowt][a[j+1]-'a'+1];
			if(nowt==0)break;
		}
		now=t[now][a[i-1]-'a'+1];
		if(now==0)break;
	}
	return sum;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",a,b);
		push();
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",a,b);
		printf("%d\n",check());
	}
	return 0;
}
/*
T3
15:49胡了一个时间复杂度很极限的做法，但是好麻烦，事已至此，先烂一会吧。
16:40写完了，但是出现了不知名错误，replace4.in会炸，但是只跑check()不printf()就不会炸
18:08修复了replace4.in会炸的bug，是我考虑不周了。
*/
