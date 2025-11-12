#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int T,n;
struct member{
	int d1,d2,d3;
}a[N];

int k;
bool vis[N];
int mx;
void dfs(int d1,int d2,int d3,int sum){
	int i,j;
	if(d1+d2+d3==n){
		mx=max(mx,sum);
		return ;
	}
	for(i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(d1<k)dfs(d1+1,d2,d3,sum+a[i].d1);
			if(d2<k)dfs(d1,d2+1,d3,sum+a[i].d2);
			if(d3<k)dfs(d1,d2,d3+1,sum+a[i].d3);
			vis[i]=0;
		}
	}
}

bool A=1,B=1;

bool cmpA(member a,member b){
	return a.d1>b.d1;
}

int sum;
void funcA(){
	int i,j;
	sort(a+1,a+1+n,cmpA);
	for(i=1;i<=n;i++) sum+=a[i].d1;
	cout<<sum;
	return ;
}


bool cmpB1(int a,int b){
	return a[a].d1>a[b].d1;
}

bool cmpB2(int a,int b){
	return a[a].d2>a[b].d2;
}

int d1[N],d2[N];
int i1,i2;
void funcB(){
	for(i=1;i<=n;i++){
		if(a[i].d1>a[i].d2){
			sum+=a[i].d1;
			d1[++i1]=i;
		}
		else sum+=a[i].d2;
		d2[++i2]=i;
	} 
	sort(d1+1,d1+1+i1,cmpB1);
	sort(d2+1,d2+1+i2,cmpB2);
	
	if(i1>k) for(i=i1;i>k;i--) sum=sum-a[d1[i]].d1+a[d1[i]].d2;
	else for(i=i1;i>k;i--) sum=sum-a[d2[i]].d2+a[d2[i]].d1;
	
	cout<<sum;
	return ;
	
}

void func(){
	int i;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].d1>>a[i].d2>>a[i].d3;
		if(a[i].d2 !=0){
			A=0;
			if(a[i].d3!=0) B=0;
		}
	}
	k=n/2;
	if(A) funcA();
	else if(B) funcB();
	else{
		dfs(0,0,0,0);
		cout<<mx<<endl;
		mx=0;
	}
}

signed main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>T;
	while(T--) func();
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
int n,m,k;
vector<int> v[N];
struct aox{
	string q,w,e,r,t,y,u,i,o,p,l,k,j,h,g,,d,s,a,z,x,c,v,bv,bn,m;
};

signed main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	while(new aox)
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
qreeenpoegbe
rgertterter
bybewyet
evegetghtb5by
tertwbethtmnevgstr
etewtertreqggg
ggereqwetbwertytery
erqty3tbecgytjeytgfhwe
ehgehjwj jyheghw54jt
whytjyqasgmnyr5kwrt
se5jh6wskgshstrjkysm,ys
rthjtrky75825 8 m n9iu5rw
4e5wgrt5gvfffw57mskwx
 jkkywsengoewpnhehqtj
 wgiwpgoep0jwe4gnw-g9h\
regheeikmorerh
heeinwgpoosdgng-ph,
bheonheio0snrpbg3k[wekg,gnehtedbht
hetopme,hpb[swgbe.rhb'erhne']]
ehehmneorbniferh;e,hpeordmhnoe
ehein rpohmd;lhg,merphmepmheheh
ehermp [[srjh[pjkw56
tgp,s[ehl.'hjmtys'y]]]]
postrjphsugnsvbmtohmpsaeththrt
eikneroisppghokhjt,jat5[perh
erpnjhoidhnubeprngflkjbjerpmnperh]
erhpmepoihenrpgfb,.per['hpk,hehr
eprhk,e[jmoepherhdfhterjk'ut]
rtmmmmmmmniphomtr;hjkyrk
myrpjsrhm;jl,sw
'tjrtmojpromrpojh;jmtr;jomrtrtjht'
qreeenpoegbe
rgertterter
bybewyet
evegetghtb5by
tertwbethtmnevgstr
etewtertreqggg
ggereqwetbwertytery
erqty3tbecgytjeytgfhwe
ehgehjwj jyheghw54jt
whytjyqasgmnyr5kwrt
se5jh6wskgshstrjkysm,ys
rthjtrky75825 8 m n9iu5rw
4e5wgrt5gvfffw57mskwx
 jkkywsengoewpnhehqtj
 wgiwpgoep0jwe4gnw-g9h\
regheeikmorerh
heeinwgpoosdgng-ph,
bheonheio0snrpbg3k[wekg,gnehtedbht
hetopme,hpb[swgbe.rhb'erhne']]
ehehmneorbniferh;e,hpeordmhnoe
ehein rpohmd;lhg,merphmepmheheh
ehermp [[srjh[pjkw56
tgp,s[ehl.'hjmtys'y]]]]
postrjphsugnsvbmtohmpsaeththrt
eikneroisppghokhjt,jat5[perh
erpnjhoidhnubeprngflkjbjerpmnperh]
erhpmepoihenrpgfb,.per['hpk,hehr
eprhk,e[jmoepherhdfhterjk'ut]
rtmmmmmmmniphomtr;hjkyrk
myrpjsrhm;jl,sw
'tjrtmojpromrpojh;jmtr;jomrtrtjht'
qreeenpoegbe
rgertterter
bybewyet
evegetghtb5by
tertwbethtmnevgstr
etewtertreqggg
ggereqwetbwertytery
erqty3tbecgytjeytgfhwe
ehgehjwj jyheghw54jt
whytjyqasgmnyr5kwrt
se5jh6wskgshstrjkysm,ys
rthjtrky75825 8 m n9iu5rw
4e5wgrt5gvfffw57mskwx
 jkkywsengoewpnhehqtj
 wgiwpgoep0jwe4gnw-g9h\
regheeikmorerh
heeinwgpoosdgng-ph,
bheonheio0snrpbg3k[wekg,gnehtedbht
hetopme,hpb[swgbe.rhb'erhne']]
ehehmneorbniferh;e,hpeordmhnoe
ehein rpohmd;lhg,merphmepmheheh
ehermp [[srjh[pjkw56
tgp,s[ehl.'hjmtys'y]]]]
postrjphsugnsvbmtohmpsaeththrt
eikneroisppghokhjt,jat5[perh
erpnjhoidhnubeprngflkjbjerpmnperh]
erhpmepoihenrpgfb,.per['hpk,hehr
eprhk,e[jmoepherhdfhterjk'ut]
rtmmmmmmmniphomtr;hjkyrk
myrpjsrhm;jl,sw
'tjrtmojpromrpojh;jmtr;jomrtrtjht'
qreeenpoegbe
rgertterter
bybewyet
evegetghtb5by
tertwbethtmnevgstr
etewtertreqggg
ggereqwetbwertytery
erqty3tbecgytjeytgfhwe
ehgehjwj jyheghw54jt
whytjyqasgmnyr5kwrt
se5jh6wskgshstrjkysm,ys
rthjtrky75825 8 m n9iu5rw
4e5wgrt5gvfffw57mskwx
 jkkywsengoewpnhehqtj
 wgiwpgoep0jwe4gnw-g9h\
regheeikmorerh
heeinwgpoosdgng-ph,
bheonheio0snrpbg3k[wekg,gnehtedbht
hetopme,hpb[swgbe.rhb'erhne']]
ehehmneorbniferh;e,hpeordmhnoe
ehein rpohmd;lhg,merphmepmheheh
ehermp [[srjh[pjkw56
tgp,s[ehl.'hjmtys'y]]]]
postrjphsugnsvbmtohmpsaeththrt
eikneroisppghokhjt,jat5[perh
erpnjhoidhnubeprngflkjbjerpmnperh]
erhpmepoihenrpgfb,.per['hpk,hehr
eprhk,e[jmoepherhdfhterjk'ut]
rtmmmmmmmniphomtr;hjkyrk
myrpjsrhm;jl,sw
'tjrtmojpromrpojh;jmtr;jomrtrtjht'
qreeenpoegbe
rgertterter
bybewyet
evegetghtb5by
tertwbethtmnevgstr
etewtertreqggg
ggereqwetbwertytery
erqty3tbecgytjeytgfhwe
ehgehjwj jyheghw54jt
whytjyqasgmnyr5kwrt
se5jh6wskgshstrjkysm,ys
rthjtrky75825 8 m n9iu5rw
4e5wgrt5gvfffw57mskwx
 jkkywsengoewpnhehqtj
 wgiwpgoep0jwe4gnw-g9h\
regheeikmorerh
heeinwgpoosdgng-ph,
bheonheio0snrpbg3k[wekg,gnehtedbht
hetopme,hpb[swgbe.rhb'erhne']]
ehehmneorbniferh;e,hpeordmhnoe
ehein rpohmd;lhg,merphmepmheheh
ehermp [[srjh[pjkw56
tgp,s[ehl.'hjmtys'y]]]]
postrjphsugnsvbmtohmpsaeththrt
eikneroisppghokhjt,jat5[perh
erpnjhoidhnubeprngflkjbjerpmnperh]
erhpmepoihenrpgfb,.per['hpk,hehr
eprhk,e[jmoepherhdfhterjk'ut]
rtmmmmmmmniphomtr;hjkyrk
myrpjsrhm;jl,sw
'tjrtmojpromrpojh;jmtr;jomrtrtjht'