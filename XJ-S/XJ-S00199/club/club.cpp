#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,id;
}m[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i=1;i<=t;i++){
		int n;
		cin >> n;
		int a1=0,b1=0,c1=0,ans=0,ans1=0;
		for(int j=1;j<=n;j++){
			cin >> m[j].a >> m[j].b >> m[j].c;
			if(max(m[j].a,max(m[j].b,m[j].c))==m[j].a){
				a1++;
				ans+=m[j].a;
				m[j].id++;
			}
			else if(max(m[j].a,max(m[j].b,m[j].c))==m[j].b){
				b1++;
				ans+=m[j].b;
				m[j].id+=2;
			}
			else{
				c1++;
				ans+=m[j].c;
				m[j].id+=3;
			}
		}
		if(n>=a1*2&&n>=b1*2&&n>=c1*2) cout << ans << endl;
		else{
			if(a1*2>n) cout <<max((ans-m[1].a+max(m[1].b,m[1].c)),(ans-m[2].a+max(m[2].b,m[2].c)));
			else if(b1*2>n) cout <<max((ans-m[1].b+max(m[1].a,m[1].c)),(ans-m[2].b+max(m[2].a,m[2].c)));
			else cout <<max((ans-m[1].c+max(m[1].b,m[1].a)),(ans-m[2].c+max(m[2].b,m[2].a)));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
