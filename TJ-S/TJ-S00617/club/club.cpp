#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

struct NODE{
	int dt;
	int num;
};

int memCnt;
NODE a[N];
NODE b[N];
NODE c[N];

long long ans;

vector<int> v[4];

int aJnB[N];

bool cmp(int x,int y){
	return x>y;
}

void slv(){
	cin>>memCnt;
	for(int i=1;i<=memCnt;i++){
		cin>>a[i].dt>>b[i].dt>>c[i].dt;
		a[i].num=1;
		b[i].num=2;
		c[i].num=3;
		if(c[i].dt>b[i].dt){
			swap(c[i],b[i]);
		}
		if(b[i].dt>a[i].dt){
			swap(b[i],a[i]);
		}
		if(c[i].dt>b[i].dt){
			swap(c[i],b[i]);
		}
		ans+=a[i].dt;
		v[a[i].num].push_back(i);
	}
	
//	cout<<"-\n";
//	for(int i=1;i<=memCnt;i++){
//		cout<<a[i].dt<<" "<<b[i].dt<<" "<<c[i].dt<<"\n";
//		cout<<a[i].num<<" "<<b[i].num<<" "<<c[i].num<<"\n\n";
//	}
//	cout<<"-";
	
	int mm=memCnt>>1;
	int ll=-1;
	for(int i=1;i<=3;i++){
		if(v[i].size()>mm){
			ll=i;
			break;
		}
	}
	if(ll==-1){
		printf("%lld\n",ans);
		return;
	}
	int vv=v[ll].size();
//	cout<<mm<<"\n";
	for(int i=0;i<vv;i++){
		aJnB[i]=a[v[ll][i]].dt-b[v[ll][i]].dt;
//		printf("%d %d %d\n",a[v[ll][i]].dt,b[v[ll][i]].dt,aJnB[i]);
	}
//	printf("\n");
	sort(aJnB,aJnB+vv);
	
//	for(int i=0;i<vv;i++){
//		cout<<aJnB[i]<<" ";
//	}
//	cout<<"\n";
	
	for(int i=0;vv-i>mm;i++){
		ans-=aJnB[i];
	}
	printf("%lld\n",ans);
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin>>T;
	while(T>0){
		ans=0;
		v[1].clear();
		v[2].clear();
		v[3].clear();
        slv();
        T--;
	}
	
	return 0;
}
