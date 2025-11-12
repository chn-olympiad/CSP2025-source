#include<bits/stdc++.h>
using namespace std;
struct type{
	char s1[10010],s2[10010];
	int l;
};
bool cmp(type x,type y){
	if(x.l<=y.l){
		return true;
	}
	return false;
}
int n,q;type a[10100];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",a[i].s1,a[i].s2);
		a[i].l=strlen(a[i].s1);
	}
	sort(a+1,a+1+n,cmp);
	type r;
	for(int i=1;i<=q;i++){
		int ans=0;
		string t,u;
		scanf("%s%s",r.s1,r.s2);
		t=r.s1;u=r.s2;
		int l1=t.size();
		for(int j=1;j<=n&&a[j].l<=l1;j++){
			if(t.find(a[j].s1)==u.find(a[j].s2)&&t.find(a[j].s1)!=string::npos){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 