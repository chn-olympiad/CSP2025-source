#include<bits/stdc++.h>
using namespace std;
struct node1{
	string s1,s2;
}a[201010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i].s1>>a[i].s2;
	string t1,t2;
	for(q;q>=1;q--){
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int l1=0,l2=0;
			while(t1.find(a[i].s1,l1)!=-1){
				l2=l1;
				l1=t1.find(a[i].s1,l1);
				l2=t2.find(a[i].s2,l2);
				if(l1==l2)ans++;
				l1++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
