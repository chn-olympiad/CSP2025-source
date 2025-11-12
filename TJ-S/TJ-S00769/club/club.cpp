#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n;
int cnt[4];
long long sum;
struct A{
	int club[4];
	int maxi;
	int secondi;
	int cha;
}a[N],b[N];
bool rule(A t1,A t2){
	return t1.cha<t2.cha;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		sum=0,cnt[1]=0,cnt[2]=0,cnt[3]=0;
		cin>>n;
		for(int p=1;p<=n;p++){
			cin>>a[p].club[1]>>a[p].club[2]>>a[p].club[3];
			int maxi=1,mini=1,secondi;
			for(int i=1;i<=3;i++){
				if (a[p].club[i]>a[p].club[maxi])
					maxi=i;
				if (a[p].club[i]<=a[p].club[mini])//·ÀÖ¹maxiÓëminiÖØ¸´ 
					mini=i;
			}
			for(int i=1;i<=3;i++){
				if(i!=maxi&&i!=mini){
					secondi=i;
					break;
				}
			}
			a[p].maxi=maxi,a[p].secondi=secondi;
			a[p].cha=a[p].club[maxi]-a[p].club[secondi];
			//cout<<maxi<<' '<<mini<<' '<<secondi<<endl;
			cnt[maxi]++;
			sum+=a[p].club[maxi];
		}
		int now=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				now=i;
			}
		}
		if(!now){
			cout<<sum<<'\n';
			continue;
		}
		int p=0;
		for(int i=1;i<=n;i++){
			if(a[i].maxi==now){
				p++;
				b[p]=a[i];
			}
		}
		sort(b+1,b+p+1,rule);
		for(int i=1;;i++){
			sum-=b[i].cha;
			cnt[now]--;
			if(cnt[now]==n/2)
				break;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
