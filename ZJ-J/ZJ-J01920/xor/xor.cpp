#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

long long n,x,s[25],k[25],a[500050][25],b[500050][25],amax,bmax;
long long flag,maxx,sum;

long long Read() {
	long long Ra=0,Rf=1;
	char Rc=getchar();
	while(Rc<'0'||Rc>'9') {
		if(Rc=='-') Rf=-1;
		Rc=getchar();
	}
	while(Rc>='0'&&Rc<='9') {
		Ra=(Ra<<1)+(Ra<<3)+(Rc&15);
		Rc=getchar();
	}
	return Ra*Rf;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//O(n^2*log k) 60+5+=65+
	n=Read(),x=Read();
	while(x) {
		k[++k[0]]=x%2;
		x/=2;
	}
	for(int i=1; i<=n; i++) {
		x=Read();
		maxx=max(maxx,x);
		while(x) {
			a[i][++a[i][0]]=x%2;
			x/=2;
		}
		for(int j=1; j<=22; j++) {
			b[i][j]=b[i-1][j]+a[i][j];
		}
	}
	if(maxx<=1&&k[0]<=1) {
		for(int i=1; i<=n; i++) {
			sum+=(a[i][1]==k[1]);
		}
	} else {
		for(int i=1; i<=n; i++) {
			for(int j=bmax+1; j<=i; j++) {
				flag=1;
				for(int w=1; w<=22; w++) {
					s[w]=(b[i][w]-b[j-1][w])%2;
					if(s[w]!=k[w]) {
						flag=0;
						break;
					}
				}
				if(flag==1) {
					sum++,bmax=i;
					break;
				}
			}
		}
	}
	cout<<sum;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
//¶à¸øµã
