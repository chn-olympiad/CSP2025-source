#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,al,aa,bb,cc;
int dj[N];
int a[N],b[N],c[N],A[N],B[N],C[N];
int ab[N],ac[N],bc[N],ba[N],ca[N],cb[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(cin>>n){
		al=aa=bb=cc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i] && a[i]>=c[i]){
				A[++aa]=i;
				al+=a[i];
			}
			else if(b[i]>=a[i] && b[i]>=c[i]){
				B[++bb]=i;
				al+=b[i];
			}
			else{
				C[++cc]=i;
				al+=c[i];
			}
			ab[i]=a[i]-b[i];
			ac[i]=a[i]-c[i];
			ba[i]=b[i]-a[i];
			bc[i]=b[i]-c[i];
			ca[i]=c[i]-a[i];
			cb[i]=c[i]-b[i];
		}
		if(aa<=n/2 && bb<=n/2 && cc<=n/2)
			cout<<al<<endl;
		else{
			if(aa>bb && aa>cc){
				for(int i=1;i<=aa;i++)
					dj[i]=min(ab[A[i]],ac[A[i]]);
				sort(dj+1,dj+aa+1);
				for(int i=1;i<=aa-n/2;i++)
					al-=dj[i];
				cout<<al<<endl;
			}
			else if(bb>aa && bb>cc){
				for(int i=1;i<=bb;i++)
					dj[i]=min(ba[B[i]],bc[B[i]]);
				sort(dj+1,dj+bb+1);
				for(int i=1;i<=bb-n/2;i++)
					al-=dj[i];
				cout<<al<<endl;
			}
			else{
				for(int i=1;i<=cc;i++)
					dj[i]=min(cb[C[i]],ca[C[i]]);
				sort(dj+1,dj+cc+1);
				for(int i=1;i<=cc-n/2;i++)
					al-=dj[i];
				cout<<al<<endl;
			}
		}
	}
	return 0;
}
