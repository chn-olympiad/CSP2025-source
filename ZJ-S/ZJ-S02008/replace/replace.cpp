#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,L=5e6,M=1e9+7,P=1e9+9,B=137;
int n,q,xm,xp,ym,yp,XM,XP,ans,l,r,len,HM[2][L+2],HP[2][L+2],pwm[L+2],pwp[L+2];
string t[2];
struct node{
	int l,hm[2],hp[2];
	string s[2];
}a[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	pwm[0]=pwp[0]=1;
	for(int i=1;i<=L;i++){
		pwm[i]=pwm[i-1]*B%M;
		pwp[i]=pwp[i-1]*B%P;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].s[0]>>a[i].s[1];
		a[i].l=a[i].s[0].length();
		for(int j=0;j<2;j++){
			a[i].s[j]=" "+a[i].s[j];
			a[i].hm[j]=a[i].hp[j]=0;
			for(int k=1;k<=a[i].l;k++){
				a[i].hm[j]=(a[i].hm[j]+pwm[k]*(a[i].s[j][k]-'a'))%M;
				a[i].hp[j]=(a[i].hp[j]+pwp[k]*(a[i].s[j][k]-'a'))%P;
			}
		}
	}
	while(q--){
		cin>>t[0]>>t[1];
		len=t[0].length();
		t[0]=" "+t[0],t[1]=" "+t[1];
		for(int j=0;j<2;j++){
			HM[j][0]=HP[j][0]=0;
			for(int i=1;i<=len;i++){
				HM[j][i]=(HM[j][i-1]+pwm[i]*(t[j][i]-'a'))%M;
				HP[j][i]=(HP[j][i-1]+pwp[i]*(t[j][i]-'a'))%P;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j+a[i].l-1<=len;j++){
				l=j,r=j+a[i].l-1;
				xm=(HM[0][r]-HM[0][l-1]+M)%M;
				xp=(HP[0][r]-HP[0][l-1]+P)%P;
				if(xm==(a[i].hm[0]*pwm[l-1]%M)&&xp==(a[i].hp[0]*pwp[l-1]%P)){
					XM=((HM[0][len]-xm+(a[i].hm[1]*pwm[l-1])%M)%M+M)%M;
					XP=((HP[0][len]-xp+(a[i].hp[1]*pwp[l-1])%P)%P+P)%P;
					if(XM==HM[1][len]&&XP==HP[1][len])++ans;
				}
				if(t[0][j]!=t[1][j])break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}