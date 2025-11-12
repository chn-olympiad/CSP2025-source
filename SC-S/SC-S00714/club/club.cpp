#include<bits/stdc++.h>
using namespace std;
int n,t,a,b,c,book1[101001],book2[101001],book3[101001],an[4];
long long ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		an[1]=0,an[2]=0,an[3]=0;
		memset(book1,0,sizeof(book1));
		memset(book2,0,sizeof(book2));
		memset(book3,0,sizeof(book3));
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(a>b&&a>c)an[1]++,ans+=a,book1[i]=max(b-a,c-a),book2[i]=-101010,book3[i]=-101010;
			if(b>a&&b>c)an[2]++,ans+=b,book2[i]=max(a-b,c-b),book1[i]=-101010,book3[i]=-101010;
			if(c>a&&c>b)an[3]++,ans+=c,book3[i]=max(a-c,b-c),book2[i]=-101010,book1[i]=-101010;
		}
		if(an[1]>n/2){
			sort(book1+1,book1+1+n,cmp);
			for(int i=1;i<=an[1]-n/2;i++)ans+=book1[i];
		}else if(an[2]>n/2){
			sort(book2+1,book2+1+n,cmp);
			for(int i=1;i<=an[2]-n/2;i++)ans+=book2[i];
		}else if(an[3]>n/2){
			sort(book3+1,book3+1+n,cmp);
			for(int i=1;i<=an[3]-n/2;i++)ans+=book3[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/