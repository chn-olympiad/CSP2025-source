//SN-J01215 齐睿渊  富平县怀德初级中学
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int a[MAXN],p[MAXN];
struct node {
	int x,y;
} allchance[MAXN];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	long long ans=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==k) {
			allchance[ans].x=i;
			allchance[ans].y=i;
			ans++;
		}
	}
	long long c;
	for(int i=1; i<=n; i++) {
		c=a[i];
		for(int j=i+1; j<=n; j++) {
			c^=(a[j]);
			if(c==k) {
				allchance[ans].x=i;
				allchance[ans].y=j;
				ans++;
			}
		}
	}
	long long h=ans;
	for(int i=0; i<ans; i++) {
		p[i]=allchance[i].y-allchance[i].x;
		
	}
	for(int i=0; i<ans; i++) {
		for(int j=i+1; j<ans; j++) {
			if(allchance[i].x!=-1&&allchance[i].y!=-1&&allchance[j].x!=-1&&allchance[j].y!=-1) {
				if((allchance[i].x<=allchance[j].x&&allchance[i].y>=allchance[j].y)||(allchance[i].y>=allchance[j].x&&allchance[i].x<=allchance[j].y)) {
					h--;
					if(p[i]<p[j]) {
						allchance[j].x=-1;
						allchance[j].y=-1;
					}else{
						allchance[i].x=-1;
						allchance[i].y=-1;
					}
				}

			}

		}
	}
	cout<<h;
	return 0;
}
