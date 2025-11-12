#include<bits/stdc++.h>
#define int long long
//#define il inline
#define put putchar
#define pii pair<int,int>
#define mk make_pair
using namespace std;
 int rd(){
	int sum=0,p=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')p=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+(ch-'0');ch=getchar();}
	return sum*p;
}
 void wr(int x){
	if(x<0)put('-'),x=-x;
	if(x>9)wr(x/10);
	put(x%10+'0');
}
const int JYAAKIOI=1e18,N=1e5+10;
int n,m,a[N],nowx,nowy,pos,b[N],fl;
 bool cmp(int x,int y){
	return x>y;
}
signed main(){
	//system("fc seat.out seat1.ans");
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=rd();m=rd();
	for(int i=1;i<=n*m;++i)a[i]=rd(),b[i]=a[i];
	sort(a+1,a+1+n*m,cmp);
	nowx=0,nowy=1,fl=1;
	for(int i=1;i<=n*m;++i)if(a[i]==b[1]){pos=i;break;}
	//cout<<pos<<endl;
	for(int i=1;i<=pos;++i){
		if(fl==1){
			++nowx;
			if(nowx>n){
				nowx=n;
				++nowy;
				fl^=1;
			}
		}
		else {
			--nowx;
			if(nowx<=0){
				nowx=1;
				++nowy;
				fl^=1;
			}
		}
	}
	wr(nowy),put(' '),wr(nowx);
	return 0;
}
