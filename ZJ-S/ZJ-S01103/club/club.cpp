#include<bits/stdc++.h>
using namespace std;
int n,t;
int a,b,c,m[100005],ch[100005],rem[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>t;t--;){
		int c1=0,c2=0,c3=0,cn=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			int m2=0,m1=max(a,max(b,c));
			if(m1==a){
				ch[i]=1;c1++;
				m2=max(b,c);
			}else if(m1==b){
				ch[i]=2;c2++;
				m2=max(a,c);
			}else{
				ch[i]=3;c3++;
				m2=max(a,b);
			}
			m[i]=m1-m2;ans+=m1;
		}
		if(c1>n/2){
			for(int i=1;i<=n;i++){
				if(ch[i]==1) rem[++cn]=m[i];
			}
		}else if(c2>n/2){
			for(int i=1;i<=n;i++){
				if(ch[i]==2) rem[++cn]=m[i];
			}
		}else{
			for(int i=1;i<=n;i++){
				if(ch[i]==3) rem[++cn]=m[i];
			}
		}
		sort(rem+1,rem+cn+1);
		for(int i=1;i<=max(max(c1,c2),c3)-n/2;i++){
			ans-=rem[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
} /*
每个人先分配在最好的社团
不合法再选择移到别的社团 
2*1e4*1e5
2147483647
2000000000 ok
多组数据 
*/
