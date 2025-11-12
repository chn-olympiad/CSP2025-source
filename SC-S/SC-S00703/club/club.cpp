#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int T,n,vis[N],num=0,cnt=0;
char bs[N];
struct stu{
	int c1;
	int c2;
	int c3;
	int bh;
}a[N];
stu b[N];
stu c[N];
bool cmp1(stu x,stu y){
	return x.c1>y.c1;
}
bool cmp2(stu x,stu y){
	return x.c2>y.c2;
}
bool cmp3(stu x,stu y){
	return x.c3>y.c3;
}
void solve(){
	int cnt=0;
	for(int i=1;i<=n/2;i++){
		cnt+=a[i].c1;
	}
	cout<<cnt<<'\n';
}
signed main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int cnt1=0,cnt2=0,cnt3=0;
		int x=n/2;
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			b[i].c1=a[i].c1;
			b[i].c2=a[i].c2;
			b[i].c3=a[i].c3;
			c[i].c1=a[i].c1;
			c[i].c2=a[i].c2;
			c[i].c3=a[i].c3;
			a[i].bh=i;
			b[i].bh=i;
			c[i].bh=i;
			if(a[i].c2!=0||a[i].c3!=0){
				flag=false;
			}
		}
		sort(a+1,a+n+1,cmp1);
		sort(b+1,b+n+1,cmp2);
		sort(c+1,c+n+1,cmp3);
		if(flag==true){
			solve();
			continue;
		}
		num=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=n){
				break;
			}
			if(vis[a[i].bh]==0){
				if(cnt1<x){
					num+=a[i].c1;
					cnt1++;
					bs[a[i].bh]='a';
				}
				else{
					if(a[i].c2>=a[i].c3&&cnt2<x){
						cnt2++;
						num+=a[i].c2;
					}
					else{
						cnt3++;
						num+=a[i].c3;
					}
				}
			}
			else{
				if(a[i].c1>max(a[i].c2,a[i].c3)){
					if(bs[a[i].bh]=='b'){
						num-=a[i].c2;
						num+=a[i].c1;
						cnt2--;
						cnt1++;
					}
					else{
						num-=a[i].c3;
						num+=a[i].c1;
						cnt3--;
						cnt1++;
					}
				}
			}
			vis[a[i].bh]=1;
			cnt++;
			if(vis[b[i].bh]==0){
				if(cnt2<x){
					num+=b[i].c2;
					cnt2++;
					bs[b[i].bh]='b';
				}
				else{
					if(b[i].c1>=b[i].c3&&cnt1<x){
						cnt1++;
						num+=b[i].c1;
					}
					else{
						cnt3++;
						num+=b[i].c3;
					}
				}
			}
			else{
				if(b[i].c2>max(b[i].c1,b[i].c3)){
					if(bs[b[i].bh]=='a'){
						num-=b[i].c1;
						num+=b[i].c2;
						cnt1--;
						cnt2++;
					}
					else{
						num-=b[i].c3;
						num+=b[i].c2;
						cnt3--;
						cnt2++;
					}
				}
			}
			vis[b[i].bh]=1;
			cnt++;
			if(vis[c[i].bh]==0){
				if(cnt3<x){
					num+=c[i].c3;
					cnt3++;
					bs[c[i].bh]='c';
				}
				else{
					if(c[i].c1>=c[i].c2&&cnt1<x){
						cnt1++;
						num+=c[i].c1;
					}
					else{
						cnt2++;
						num+=c[i].c2;
					}
				}
			}
			else{
				if(c[i].c2>max(c[i].c1,c[i].c3)){
					if(bs[c[i].bh]=='a'){
						num-=c[i].c1;
						num+=c[i].c3;
						cnt1--;
						cnt3++;
					}
					else{
						num-=c[i].c2;
						num+=c[i].c3;
						cnt2--;
						cnt3++;
					}
				}
			}
			vis[c[i].bh]=1;
			cnt++;
		}
		cout<<num<<'\n';
	}
	return 0;
} 