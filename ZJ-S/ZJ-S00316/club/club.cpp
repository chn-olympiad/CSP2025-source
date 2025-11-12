#include <bits/stdc++.h>
using namespace std;
int n,m;
int u;
int a,b,c;
int x,y,z;
long long ans;
struct node{
	int Max1,ch;
	int id;
}v[100010];
bool cmp(node x, node y){
	if(x.ch!=y.ch) return x.ch<y.ch;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	cin >> _;
	while(_--){
		u=0;
		a=0;
		b=0;
		c=0;
		ans=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> x >> y >> z;
			v[i].Max1=max(x,max(y,z));
			if(v[i].Max1==x){
				v[i].id=1;
				a++;
				v[i].ch=v[i].Max1-max(y,z);
			}
			if(v[i].Max1==y){
				v[i].id=2;
				b++;
				v[i].ch=v[i].Max1-max(x,z);
			}
			if(v[i].Max1==z){
				v[i].id=3;
				c++;
				v[i].ch=v[i].Max1-max(y,x);
			}
		}
		int it;
		u=max(a,max(b,c));
		if(u==a) it=1;
		else if(u==b) it=2;
		else if(u==c) it=3;
		for(int i=1;i<=n;i++){
			ans+=v[i].Max1;
			cout << v[i].id << v[i].ch << v[i].Max1 << endl;
		}
		sort(v+1,v+n+1,cmp);
		u-=n/2;
		for(int i=1;i<=n&&u>0;i++){
			if(v[i].id==it){
				ans-=v[i].ch;
				u--;
			}
		}
		cout << ans << endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

