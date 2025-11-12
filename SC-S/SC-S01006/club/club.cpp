#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int T;int b[4][N];int maxn[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin>>T;
	while(T--){
		int n;cin>>n;
		if(n==2){
			int aw,bw,cw,dw,ew,fw;cin>>aw>>bw>>cw>>dw>>ew>>fw;
			int abc1=max(aw,max(bw,cw));int abc3=min(aw,min(bw,cw));
			int abc2,def2;
			if(aw!=abc1&&aw!=abc3) abc2=aw;
			else if(bw!=abc1&&bw!=abc3) abc2=bw;
			else if(cw!=abc1&&cw!=abc3) abc2=cw;
			int def1=max(dw,max(ew,fw));int def3=min(dw,min(ew,fw));
			if(dw!=def1&&dw!=def3) def2=dw;
			else if(ew!=def1&&ew!=def3) def2=ew;
			else if(fw!=def1&&fw!=def3) def2=fw;
			if(abc1>=def1&&abc1==aw&&def1==dw){cout<<abc1+def2;return 0;}
			else if(abc1>=def1&&abc1==aw&&def1==ew){cout<<abc1+def2;return 0;}
			else if(abc1>=def1&&abc1==aw&&def1==fw){cout<<abc1+def2;return 0;}
			else if(abc1>=def1&&abc1==bw&&def1==dw){cout<<abc1+def2;return 0;}
			else if(abc1>=def1&&abc1==bw&&def1==ew){cout<<abc1+def2;return 0;}
			else if(abc1>=def1&&abc1==bw&&def1==fw){cout<<abc1+def2;return 0;}
			else if(abc1>=def1&&abc1==cw&&def1==dw){cout<<abc1+def2;return 0;}
			else if(abc1>=def1&&abc1==cw&&def1==ew){cout<<abc1+def2;return 0;}
			else if(abc1>=def1&&abc1==cw&&def1==fw){cout<<abc1+def2;return 0;}
			else if(abc1<def1&&abc1==aw&&def1==dw){cout<<abc2+def1;return 0;}
			else if(abc1<def1&&abc1==bw&&def1==dw){cout<<abc2+def1;return 0;}
			else if(abc1<def1&&abc1==cw&&def1==dw){cout<<abc2+def1;return 0;}
			else if(abc1<def1&&abc1==aw&&def1==ew){cout<<abc2+def1;return 0;}
			else if(abc1<def1&&abc1==bw&&def1==ew){cout<<abc2+def1;return 0;}
			else if(abc1<def1&&abc1==cw&&def1==ew){cout<<abc2+def1;return 0;}
			else if(abc1<def1&&abc1==aw&&def1==fw){cout<<abc2+def1;return 0;}
			else if(abc1<def1&&abc1==bw&&def1==fw){cout<<abc2+def1;return 0;}
			else if(abc1<def1&&abc1==cw&&def1==fw){cout<<abc2+def1;return 0;}
			else if(abc2+def1>abc1+def2){cout<<abc2+def1;return 0;}
			else if(abc3+def1>abc1+def3){cout<<abc3+def1;return 0;}
			else if(abc1+def2>abc2+def1){cout<<abc1+def2;return 0;}
			else if(abc1+def3>abc3+def1){cout<<abc1+def3;return 0;}
			else {cout<<"CCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCF";return 0;}
		}
		int mp=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>b[j][i];
				maxn[i]=max(maxn[i],b[j][i]);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int q=1;
			for(int j=1;j<=3;j++){
				if(b[j][i]==maxn[i]&&q<=mp){
					q++; 
					ans+=maxn[i];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*.......................................
.........................................
....../...........................\......
...../_____________________________\.....
.....|       ___         ___       |.....
.....|________0____,_,____0________|.....
.....|                             |.....
.....\____________  o  ____________/.....
....................l....................
....................l....................
....................l....................
....................l....................
.........d----------l----------b.........
....................l....................
....................l....................
....................l....................
....................l....................
....................l....................
...................l.l...................
..................l...l..................
.................l.....l.................
................l.......l................
...............l.........l...............
............._l...........l_.............
*/