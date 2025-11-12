#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int q,n;
long long sum;
struct node{
	int dx;
	int m1,m2,m3,s1,s2,s3;
}a[N];
int num[4];int fs;
bool cmp(node i,node j){
	if(fs==1) return min(i.s1,i.s3)<min(j.s1,j.s3);
	if(fs==2) return min(i.s1,i.s2)<min(j.s1,j.s2);
	if(fs==3) return min(i.s2,i.s3)<min(j.s2,j.s3);
}
int check(node i){
	if(fs==1){
		int t=min(i.s1,i.s3);
		if(t==i.s1) return 2;
		else return 3;
	}
	if(fs==2){
		int t=min(i.s1,i.s2);
		if(t==i.s1) return 1;
		else return 3;
	}
	if(fs==3){
		int t=min(i.s2,i.s3);
		if(t==i.s2) return 2;
		else return 1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&q);
	for(int p=1;p<=q;p++){
		sum=0;memset(num,0,sizeof(num));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].m1,&a[i].m2,&a[i].m3);
		}
		for(int i=1;i<=n;i++){
			int k=max(a[i].m1,max(a[i].m2,a[i].m3));
			if(k==a[i].m1){num[1]++;a[i].dx=1;}
			if(k==a[i].m2){num[2]++;a[i].dx=2;}
			if(k==a[i].m3){num[3]++;a[i].dx=3;}
			a[i].s1=abs(a[i].m1-a[i].m2);
			a[i].s2=abs(a[i].m2-a[i].m3);
			a[i].s3=abs(a[i].m3-a[i].m1);
			sum+=k;
		}
		bool flag=1;
		for(int i=1;i<=3;i++){
			if(num[i]>(n/2)){
				fs=i;flag=0;
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(flag==1) break;
			if(num[fs]<=(n/2)) break;
			if(a[i].dx!=fs) continue;
			int ch=check(a[i]);
			num[ch]++;
			if(fs==1) sum=sum-a[i].m1;
			if(ch==1) sum=sum+a[i].m1;
			if(fs==2) sum=sum-a[i].m2;
			if(ch==2) sum=sum+a[i].m2;
			if(fs==3) sum=sum-a[i].m3;
			if(ch==3) sum=sum+a[i].m3;
			a[i].dx=ch;
			num[fs]--;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0; 
} 
