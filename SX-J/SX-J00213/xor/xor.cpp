#include <bits/stdc++.h>
using namespace std;

const int MAX=5e5+10;
const int MAXM=1e3+4;

int k;

int n,a[MAX];
int l[MAX],r[MAX],o=1;
int f[MAXM][MAXM];

int num=0;

struct edge{
	int l,r,len;
};
edge p[MAX];

bool cmp(edge a,edge b){
    if(a.len==b.len) return a.r<b.l;
   else return a.len<b.len;
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
//
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];

    int h=1;
    for(int i=1;i<=n;i++){
    	f[i][i]=a[i];
    	for(int j=i;j<=n;j++){
            f[i][j]=f[i][j-1]^a[j];
            if(f[i][j]==k){
            	p[h].l=i;
            	p[h].r=j;
            	p[h].len=j-i+1;
            	h++;
			}
		}
	}

    sort(p+1,p+h,cmp);

    l[1]=p[1].l,r[1]=p[1].r;
    if (h>1) num=1;
//    cout<<h;
//    for(int i=1;i<h;i++){
//    	cout<<p[i].l<<" "<<p[i].r<<endl;
//	}
    for(int i=2;i<h;i++){
    	int ll=p[i].l,rr=p[i].r;
    	bool flag=0;
    	if(rr<l[1]||ll>r[1]) {
		num++;
		l[1]=min(l[1],ll);
		r[1]=max(l[1],rr);}
//        for(int j=1;j<=o;j++){
//        	if((ll>l[j]&&ll<r[j])||(rr<r[j]&&rr>r[j])){
//        		flag=1;
//        		break;
//			}
//		}
//		if(flag==0){
//			num++;
//			o++;
//			l[o]=ll;
//			r[o]=rr;
//		}
	}

	cout<<num;
	return 0;
}