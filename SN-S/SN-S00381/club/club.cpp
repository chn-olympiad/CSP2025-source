//李骏铭 西安市曲江第一学校 SN-N00381
#include<bits/stdc++.h>
using namespace std;
int t,n;

void aa() {
	cin >> n;
	int q=0,w=0,e=0,p=0,o=0,u=0;
	int a[100005],m[100005],c[100005];
	for (int i=1; i<=n; i++) {

		cin >> a[i] >> c[i] >> m[i];
		if (q>n/2) {
			int h=1e5,gg;
			for (int j=1; j<=i-1; j++) {
				if (h>a[j]) {
					h=a[j];
					gg=j;
				}
			}
			if (h>=a[i]) {

				if (p+o+u-a[gg]<p+o+u+c[gg]-a[gg]||p+o+u-a[gg]<p+o+u+m[gg]-a[gg]) {
					p-=a[gg];
					p+=a[i];
					
					if (c[gg]>m[gg]) {
						o+=c[gg];
						w++;
					} else {
						u+=m[gg];
						e++;
					}
				}

			} else {
				p-=a[gg];
				p+=a[i];
		
				if (c[gg]>m[gg]) {
					o+=c[gg];
					w++;
				} else {
					u+=m[gg];
					e++;
				}
			}
		}
		if (w>n/2) {
			int h=1e5,gg;
			for (int j=1; j<=i-1; j++) {
				if (h>c[j]) {
					h=c[j];
					gg=j;
				}
			}
			if (h>=c[i]) {

				if (p+o+u-c[gg]<p+o+u+a[gg]-c[gg]||p+o+u-c[gg]<p+o+u+m[gg]-c[gg]) {
					o-=c[gg];
					o+=c[i];
	
					if (a[gg]>m[gg]) {
						p+=c[gg];
						q++;
					} else {
						u+=m[gg];
						e++;
					}
				}

			} else {
				o-=c[gg];
				o+=c[i];
				
				if (a[gg]>m[gg]) {

					p+=a[gg];

					q++;
				} else {

					u+=m[gg];

					e++;
				}
			}
		}
		if (e>n/2) {
			int h=1e5,gg;
			for (int j=1; j<=i-1; j++) {
				if (h>m[j]) {
					h=m[j];
					gg=j;
				}
			}
			if (h>=a[i]) {
				if (p+o+u-m[gg]<p+o+u+a[gg]-m[gg]||p+o+u-m[gg]<p+o+u+c[gg]-m[gg]) {
					p-=a[gg];
					p+=a[i];
				
					if (c[gg]>a[gg]) {
						o+=c[gg];
						w++;
					} else {
						p+=m[gg];
						q++;
					}
				}
			} else {
				u-=m[gg];
				u+=m[i];
			
				if (c[gg]>a[gg]) {
					o+=c[gg];
					w++;
				} else {
					p+=a[gg];
					q++;
				}
			}
		} else {
			if (a[i]>c[i]&&a[i]>m[i]) {
				q++;
				p+=a[i];
			} else if(a[i]<c[i]&&c[i]>m[i]) {
				w++;
				o+=c[i];
			} else {
				e++;
				u+=m[i];
			}
		}

		if (q>n/2) {
			int h=1e5,gg;
			for (int j=1; j<=i-1; j++) {
				if (h>a[j]) {
					h=a[j];
					gg=j;
				}
			}
			if (h>=a[i]) {
				if (p+o+u-a[gg]<p+o+u+c[gg]-a[gg]||p+o+u-a[gg]<p+o+u+m[gg]-a[gg]) {
					p-=a[gg];
					p-=a[i];
					
		
					p+=a[i];
					q--;
					if (c[gg]>m[gg]) {
						o+=c[gg];
						w++;
					} else {
						u+=m[gg];
						e++;
					}
				}
			} else {
				p-=a[gg];
				q--;
				if (c[gg]>m[gg]) {
					o+=c[gg];
					w++;
				} else {
					u+=m[gg];
					e++;
				}
			}
		}
		if (w>n/2) {
			int h=1e5,gg;
			for (int j=1; j<=i-1; j++) {
				if (h>c[j]) {
					h=c[j];
					gg=j;
				}
			}
			if (h>=c[i]) {
				if (p+o+u-c[gg]<p+o+u+a[gg]-c[gg]||p+o+u-c[gg]<p+o+u+m[gg]-c[gg]) {
					o-=c[gg];
					o-=c[i];
					o+=c[i];
					
					w--;
					if (a[gg]>m[gg]) {
						p+=a[gg];
						q++;
					} else {
						u+=m[gg];
						e++;
					}
				}
			} else {
				o-=c[gg];
				w--;
				if (a[gg]>m[gg]) {

					p+=a[gg];

					q++;
				} else {

					u+=m[gg];

					e++;
				}
			}
		}
		if (e>n/2) {
			int h=1e5,gg;
			for (int j=1; j<=i; j++) {
				if (h>m[j]) {
					h=m[j];
					gg=j;
				}
			}
			if (h>=a[i]) {
				if (p+o+u-m[gg]<p+o+u+a[gg]-m[gg]||p+o+u-m[gg]<p+o+u+c[gg]-m[gg]) {
					u-=m[i];
					u-=m[gg];
					
					
					u+=m[i];
					e--;
					if (c[gg]>m[gg]) {
						o+=c[gg];
						w++;
					} else {
						u+=m[gg];
						e++;
					}
				}
			} else {
				u-=m[gg];
				e--;
				if (c[gg]>a[gg]) {
					o+=c[gg];
					w++;
				} else {
					p+=a[gg];
					q++;
				}
			}
		}



	}
	cout << u+o+p << '\n';


}
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		aa();
	}
	return 0;
}

