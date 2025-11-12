#include<bits/stdc++.h>
#define debug(a) cout<<a.i<<" "<<a.ans<<" "<<a.num<<"\n";
using namespace std;
int t,n,num1,num2,num3;
struct dd{
	int num,i,ans;
}b[100005];
void clearnow(){
	n=0;
	num1=0;
	num2=0;
	num3=0;
	for(int i=1;i<=100004;i++){
		b[i].ans=0;
		b[i].num=0;
		b[i].i=0;
	}
}
bool cmp(dd a,dd c){
	if(a.i==c.i){
		return a.num>c.num;
	}
	else {
		return a.i<c.i;
	}
}
void solve(){
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(x>y&&y>z){
			b[i].ans=x;
			b[i].num=x-y;
			b[i].i=1;
		}
		else if(x>z&&z>y){
			b[i].ans=x;
			b[i].num=x-z;
			b[i].i=1;
		}
		else if(y>z&&z>x){
			b[i].ans=y;
			b[i].num=y-z;
			b[i].i=2;
		}
		else if(y>x&&x>z){
			b[i].ans=y;
			b[i].num=y-x;
			b[i].i=2;
		}
		else if(z>y&&y>x){
			b[i].ans=z;
			b[i].num=z-y;
			b[i].i=3;
		}
		else if(z>y&&x>y){
			b[i].ans=z;
			b[i].num=z-x;
			b[i].i=3;
		}
		else if(x>z&&y>z&&x==y){
			b[i].ans=x;
			b[i].num=0;
			b[i].i=1;
		}
		else if(x>y&&z>y&&x==z){
			b[i].ans=x;
			b[i].num=0;
			b[i].i=1;
		}
		else if(z>x&&y>x&&z==y){
			b[i].ans=y;
			b[i].num=0;
			b[i].i=2;
		}
		
		else if(z>x&&z>y&&x==y){
			b[i].ans=z;
			b[i].num=z-x;
			b[i].i=3;
		}
		else if(y>x&&y>z&&x==z){
			b[i].ans=y;
			b[i].num=y-x;
			b[i].i=2;
		}
		else if(x>y&&x>z&&z==y){
			b[i].ans=x;
			b[i].num=x-y;
			b[i].i=1;
		}
		else if(z==x&&x==y){
			b[i].ans=z;
			b[i].num=0;
			b[i].i=2;
		}
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(b[i].i==1){
			num1++;
			ans+=b[i].ans;
			if(num1>n/2){
				num1--;
				ans-=b[i].num;
			}
		}
		if(b[i].i==2){
			num2++;
			ans+=b[i].ans;
			if(num2>n/2){
				num2--;
				ans-=b[i].num;
			}
		}
		if(b[i].i==3){
			num3++;
			ans+=b[i].ans;
			if(num3>n/2){
				num3--;
				ans-=b[i].num;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		clearnow();
		solve();
	}
}
