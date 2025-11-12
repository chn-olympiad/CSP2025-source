#include<bits/stdc++.h>
using namespace std;
int n,p,x;
int a[500002];
int t[1100002];
int cnt;
int l[500002];
int f[500002];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&p);
	t[p]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		x^=a[i];
		if(t[x]){
			l[i]=t[x];
		}else{
			l[i]=n+2;
		}
		t[x^p]=i+1;
	}
	f[n+1]=-n;
//	printf("%d\n",cnt);
//	for(int i=1;i<=cnt;i++){
//		printf("%d %d\n",l[i],r[i]);
//	}
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1],f[l[i]-1]+1);
	}
//	for(int i=1;i<=n;i++){
//		printf("%d ",f[i]);
//	}
//	puts("");
	printf("%d",f[n]);
	return 0;
}
/*
play with chrome://dino,good good!----9:09
If I got 265,I could get 1= in the last year.So an I get 1= if I get 265?
I think not
Maybe I need 300.
I think I thought of the answer just now!----9:29
Fuck,it's FAKE----9:30
trie?----9:34
FAKE----9:35
I think I thought of the answer just now again!----9:39
O(n)
done!----10:16
*/