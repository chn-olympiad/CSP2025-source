#include<bits/stdc++.h>
using namespace std;
int a[100010][4],n;
struct node {
	int ii,f,s,ch;
	friend bool operator < (node a,node b) {
		return a.ch>b.ch;
	}
} s[100010];
void judge1(int x,int y,int z,int i) {
	int max1=max(x,max(y,z));
	if(max1==x) {
		s[i].f=1;
		int max2=max(y,z);
		if(max2==y) {
			s[i].s=2;
		} else {
			s[i].s=3;
		}
		s[i].ch=max1-max2;
	} else if(max1==y) {
		s[i].f=2;
		int max2=max(x,z);
		if(max2==x) {
			s[i].s=1;
		} else {
			s[i].s=3;
		}
		s[i].ch=max1-max2;
	} else {
		s[i].f=3;
		int max2=max(x,y);
		if(max2==x) {
			s[i].s=1;
		} else {
			s[i].s=2;
		}
		s[i].ch=max1-max2;
	}
	return ;
}
int cnt1,cnt2,cnt3,ans;
void judge2(int i) {
	if(s[i].f==1) {
		if(cnt1+1<=n/2) {
			ans+=a[s[i].ii][s[i].f];
			cnt1++;
		} else {
			ans+=a[s[i].ii][s[i].s];
			if(s[i].s==2) {
				cnt2++;
			} else {
				cnt3++;
			}
		}
	} else if(s[i].f==2) {
		if(cnt2+1<=n/2) {
			ans+=a[s[i].ii][s[i].f];
			cnt2++;
		} else {
			ans+=a[s[i].ii][s[i].s];
			if(s[i].s==1) {
				cnt1++;
			} else {
				cnt3++;
			}
		}
	} else {
		if(cnt3+1<=n/2) {
			ans+=a[s[i].ii][s[i].f];
			cnt3++;
		} else {
			ans+=a[s[i].ii][s[i].s];
			if(s[i].s==1) {
				cnt1++;
			} else {
				cnt2++;
			}
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int w=1; w<=t; w++) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			s[i].ii=i;
			judge1(a[i][1],a[i][2],a[i][3],i);
		}
		sort(s+1,s+1+n);
		cnt1=0,cnt2=0,cnt3=0,ans=0;
		for(int i=1; i<=n; i++) {
			judge2(i);		
		}		
		cout<<ans<<"\n";
	}
	return 0;
}
