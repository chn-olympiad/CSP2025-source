#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
struct node{
	int l,r,c;
}b[500005];
inline bool cmp(node a,node b){
	return a.l<b.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int cnt=0;
	int last=0;
	for(int i=1;i<=n;){
		for(int j=i;j<=n;j++){
			int sum=a[i];
			for(int p=i+1;p<=j;p++){
				sum=sum^a[p];
			}
			if(sum==k){
				b[++cnt].l=i;
				b[cnt].r=j;
				break;
			}
		//	if(j-i+1>=25) break;
		}
		if(last!=cnt){
			last=cnt;
			i=b[cnt].r+1;
		}else{
			i++;
		}
	}
	printf("%d",cnt);
	/*sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int k=1;k<=cnt;k++){
				
			}
		}
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}

