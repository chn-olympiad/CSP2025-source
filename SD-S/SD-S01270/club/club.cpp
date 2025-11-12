#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+5;
struct S{
	int val,id,tp;
	bool operator<(S b){
		return val<b.val;
	}
}s[3*N];
void read(int&x){
	char ch=getchar();x=0;
	while(!isdigit(ch)){ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
}
int sle[N];
int a[N][4];
int w[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,x;read(t);
	while(t--){
		ll sum=0;
		x=0;
		cin>>n;
		int A,B,C;
		for(int i=1;i<=n;i++){
			read(A);read(B);read(C);
			a[i][1]=A,a[i][2]=B,a[i][3]=C;
			s[++x].id=i,s[x].tp=1,s[x].val=A;
			s[++x].id=i,s[x].tp=2,s[x].val=B;
			s[++x].id=i,s[x].tp=3,s[x].val=C;
			sle[i]=0;
		}
		sort(s+1,s+x+1);
		int tol[4]={0,0,0,0};
		for(int i=x;i>=1;i--){
			if(!sle[s[i].id]){
				sum+=s[i].val;
				sle[s[i].id]=s[i].tp;
				tol[s[i].tp]++;
			}
		}
		int olim=0,k;
		for(int i=1;i<=3;i++)if(tol[i]>n/2)olim=i,k=tol[i]-n/2;
		if(olim){
			for(int i=1;i<=n;i++){
				w[i]=-2e4-5;
				if(sle[i]==olim)
					for(int j=1;j<=3;j++){
						if(j==olim)continue;
						w[i]=max(w[i],a[i][j]-a[i][olim]);
					}
			}
			sort(w+1,w+n+1);
			for(int i=n;i>=1&&k;i--){
				sum+=w[i];k--;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
