#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
long long maxx;
struct Node{
	int i1,i2,i3,num;
	int anum,acnt;
	int inum,icnt;
}a[N];
int cnt1,cnt2,cnt3,cnt4;
bool cmp(Node x,Node y){
	if(x.num>y.num) return true;
	else{
		if(x.num==y.num){
			if(x.anum>y.anum) return true;
			else if(x.anum==y.anum) return x.inum<y.inum;
			else return false;
		}
		else return false; 
	}
}
bool cmp1(Node x,Node y){
	return x.num>y.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		maxx=0;
		cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			a[i].anum=0;
			a[i].inum=20110;
		}
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i].i1 >> a[i].i2 >> a[i].i3;
			if(a[i].i3==0) cnt4++;
			if(a[i].i1>=a[i].anum) a[i].anum=a[i].i1,a[i].acnt=1;
			if(a[i].i2>=a[i].anum) a[i].anum=a[i].i2,a[i].acnt=2;
			if(a[i].i3>=a[i].anum) a[i].anum=a[i].i3,a[i].acnt=3;
			if(a[i].i1<=a[i].inum) a[i].inum=a[i].i1,a[i].icnt=1;
			if(a[i].i2<=a[i].inum) a[i].inum=a[i].i2,a[i].icnt=2;
			if(a[i].i3<=a[i].inum) a[i].inum=a[i].i3,a[i].icnt=3;
			a[i].num=(a[i].anum-a[i].i1)+(a[i].anum-a[i].i2)+(a[i].anum-a[i].i3);
		}
		if(cnt4==n){
			for(int i=1;i<=n;i++){
				if(a[i].i1>=a[i].anum) a[i].anum=a[i].i1,a[i].acnt=1;
				if(a[i].i2>=a[i].anum) a[i].anum=a[i].i2,a[i].acnt=2;
				if(a[i].i1<=a[i].inum) a[i].inum=a[i].i1,a[i].icnt=1;
				if(a[i].i2<=a[i].inum) a[i].inum=a[i].i2,a[i].icnt=2;
				a[i].num=(a[i].anum-a[i].i1)+(a[i].anum-a[i].i2);
			}
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(a[i].acnt==1){
					if(cnt1<n/2){
						maxx+=a[i].i1;
						cnt1++;
					}else{				
						maxx+=a[i].i2;
						cnt2++;
					}
				}else{
					if(cnt2<n/2){
						maxx+=a[i].i2;
						cnt2++;
					}else{
						maxx+=a[i].i1;
						cnt1++;					
					}
				}
			}
			cout << maxx << endl;
		}else{
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(a[i].acnt==1){
					if(cnt1<n/2){
						maxx+=a[i].i1;
						cnt1++;
					}else{
						if(a[i].icnt==2){
							maxx+=a[i].i3;
							cnt3++;
						}else{
							maxx+=a[i].i2;
							cnt2++;
						}
					}
				}else if(a[i].acnt==2){
					if(cnt2<n/2){
						maxx+=a[i].i2;
						cnt2++;
					}else{
						if(a[i].icnt==1){
							maxx+=a[i].i3;
							cnt3++;
						}else{
							maxx+=a[i].i1;
							cnt1++;
						}
					}
				}else{
					if(cnt3<n/2){
						maxx+=a[i].i3;
						cnt3++;
					}else{
						if(a[i].icnt==2){
							maxx+=a[i].i1;
							cnt1++;
						}else{
							maxx+=a[i].i2;
							cnt2++;
						}
					}
				}
			}
			cout << maxx << endl;
		}
		
	}
	return 0;
} 
