#include<bits/stdc++.h>
using namespace std;
#define int long long
struct qwe{
	int a,b,c;
};qwe aa[200005];
struct wer{
	int bh,sz;
};wer a1[200005];
int e,f,g,h;
bool cmp(wer x1,wer x2){
	return x1.sz>x2.sz;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>e;
	for(int i=1;i<=e;i++){
		cin>>f;
		g=0;
		for(int i=1;i<=f;i++) cin>>aa[i].a>>aa[i].b>>aa[i].c;
		for(int i=1;i<=f;i++){
			a1[i].sz=max(aa[i].a,max(aa[i].b,aa[i].c));
			if(a1[i].sz==aa[i].a) a1[i].bh=1;
			else if(a1[i].sz==aa[i].b) a1[i].bh=2;
			else if(a1[i].sz==aa[i].c) a1[i].bh=3;
		}
		sort(a1+1,a1+f+1,cmp);
		int ls1=0,ls2=0,ls3=0;
		for(int i=1;i<=f;i++){
			if(ls1<=f/2&&a1[i].bh==1){
				ls1++;
				g+=a1[i].sz;
			}
			if(ls2<=f/2&&a1[i].bh==2){
				ls2++;
				g+=a1[i].sz;
			}
			if(ls3<=f/2&&a1[i].bh==3){
				ls3++;
				g+=a1[i].sz;
			}
		}
		cout<<g<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}