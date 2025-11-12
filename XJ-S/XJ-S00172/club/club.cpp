#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][5], f[N], lk[N];
struct node {
	int k, x;
}; node ab[N], ac[N], bc[N];
int cmp(node p, node q) {
	return p.x<q.x;
}
int r[15], t[15], u[15], maxans=0;
int club1(int n, int k, int n1, int n2, int n3, int suma) {
    if(n1>n/2 || n2>n/2 || n3>n/2) {
        return 0;
    }
    if(k>n) {
         return suma;
    }
    return max(club1(n, k+1, n1+1, n2, n3, suma+a[k][1]), max(club1(n, k+1, n1, n2+1, n3, suma+a[k][2]), club1(n, k+1, n1, n2, n3+1, suma+a[k][3])));
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	int t, n;
	cin>>t;
	while(t--) {
		int bn=0, cn=0, dn=0, ans=0, bl=1, cl=1, dl=1, lp=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]==0 && a[i][3]==0) lp++;
			ab[i].k=i, ac[i].k=i, bc[i].k=i;
			ab[i].x=abs(a[i][1]-a[i][2]), ac[i].x=abs(a[i][1]-a[i][3]), bc[i].x=abs(a[i][2]-a[i][3]);
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]) {
				ans+=a[i][1]; bn++;
			} else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]) {
				ans+=a[i][2]; cn++;
			} else {
				ans+=a[i][3]; dn++;
			}
		} if(n<=10) {
		    cout<<club1(n, 1, 0, 0, 0, 0)<<endl;
		} else if(lp==n) {
            int sum=0;
            for(int i=1; i<=n; i++) {
                lk[i]=a[i][1];
            } sort(lk+1, lk+n+1);
            for(int i=n; i>n/2; i--) {
                sum+=lk[i];
            } cout<<sum<<endl;
		} else {
            sort(ab+1, ab+n+1, cmp);
            sort(ac+1, ac+n+1, cmp);
            sort(bc+1, bc+n+1, cmp);
            if(bn>(n/2)) {
                for(int i=1; i<=bn-(n/2); i++) {
                    while(f[ab[cl].k]) cl++;
                    while(f[ac[dl].k]) dl++;
                    if(ac[cl].x<ab[dl].x) {
                        ans-=ac[cl].x;
                        f[ac[cl].k]=1;
                        cl++;
                    } else {
                        ans-=ab[dl].x;
                        f[ab[dl].k]=1;
                        dl++;
                    }
                }
            } else if(cn>(n/2)) {
                for(int i=1; i<=cn-(n/2); i++) {
                    while(f[ab[bl].k]) bl++;
                    while(f[bc[dl].k]) dl++;
                    if(ab[bl].x<bc[dl].x) {
                        ans-=ab[bl].x;
                        f[ab[bl].k]=1;
                        bl++;
                    } else {
                        ans-=bc[dl].x;
                        f[bc[dl].k]=1;
                        dl++;
                    }
                }
            } else {
                for(int i=1; i<=dn-(n/2); i++) {
                    while(f[ac[cl].k]) cl++;
                    while(f[bc[bl].k]) bl++;
                    if(ac[cl].x<bc[bl].x) {
                        ans-=ac[cl].x;
                        f[ac[cl].k]=1;
                        cl++;
                    } else {
                        ans-=bc[bl].x;
                        f[bc[bl].k]=1;
                        bl++;
                    }
                }
            } cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
