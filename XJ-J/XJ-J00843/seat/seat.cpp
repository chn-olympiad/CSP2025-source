#include <bits/stdc++.h>
using namespace std;
const int N=500;
struct Node{
	int score,pos;
	bool operator <(const Node &x)const{
		return score>x.score;
	}
}a[N];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].score);
		a[i].pos=i;
	}
	sort(a+1,a+1+n*m);
	int lie=1,hang=1,k=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].pos==1){
			k=i;
			break;
		}
	}
//	cout<<k<<endl;
	if((k/n+((bool)(k%n)))%2==1){
//		cout<<111<<endl;
		if(k%n==0)lie=m;
		else lie=k%n;
	}else {
		if(k%n==0)lie=1;
		else lie=m-k%n+1;
	}
	printf("%d %d\n",k/n+((bool)(k%n)),lie);
	return 0;
}
