#include<bits/stdc++.h> 
using namespace std;
int myt,myn,cnt[3],res,aar[100002][3];
struct node{
	int my1,my2,my3,mmax,mw;
}ma[100002];
bool cmp(node nn1,node nn2){
	return nn1.mmax>=nn2.mmax;
}
bool cmp2(node nnn1,node nnn2){
	return nnn1.my1>=nnn2.my1;
}
int fun3(int f31,int f32,int f33){
	int frr = max(f31,f32);
	frr = max(frr,f33);
	return frr;
}
int fun1(int f11,int f12,int f13,int f1m){
	int fn1;
	if(ma[f1m].mmax == f11) fn1=0;
	else if(ma[f1m].mmax == f12) fn1=1;
	else if(ma[f1m].mmax == f13) fn1=2;
	return fn1;
} 
int fun2(int fn2){
	if(ma[fn2].mw==0){
		if(aar[fn2][1]>aar[fn2][2]) return 1;	
		else return 2;
	}else if(ma[fn2].mw==1){
		if(aar[fn2][0]>aar[fn2][2]) return 0;	
		else return 2;
	}else {
		if(aar[fn2][0]>aar[fn2][1]) return 0;	
		else return 1;
	}
}
void fun5(){
	for(int i=1;i<=myn;i++){
		if(ma[i].my1>=ma[i].my2){
			ma[i].mmax = ma[i].my1;
			ma[i].mw = 0;
		}else {
			ma[i].mmax = ma[i].my2;
			ma[i].mw = 1;
		}
	}
	sort(ma+1,ma+1+myn,cmp);
	for(int i=1;i<=myn;i++){
		if(ma[i].my1==ma[i].my2){
			res+=ma[i].my1;
			continue;
		}else if(cnt[ma[i].mw]>=myn/2){
			if(ma[i].mw ==0){
				res+=ma[i].my2;
				cnt[1]+=1;
			}
			else{
				res+=ma[i].my1;
				cnt[0] +=1;
			} 
		}else{
			res+=ma[i].mmax;
			cnt[ma[i].mw]+=1; 
		}
	}
	cout << res << '\n';
	return ;
}
bool fun4(){
	bool fflag = false;
	for(int i=1;i<=myn;i++){
		if(ma[i].my3!=0){
			fflag = true;
			break;
		} 
	}
	if(fflag==true) return false;
	for(int i=1;i<=myn;i++){
		if(ma[i].my2!=0){
			fun5();
			fflag = true;
			break;
		} 
	}
	if(fflag==true) return true;
	sort(ma+1,ma+1+myn,cmp2);
	for(int i=1;i<=myn/2;i++){
		res+=ma[i].my1;
	}
	cout << res << '\n';
	return true;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> myt;
	while(myt--){
		res=0;
		memset(cnt,0,sizeof(cnt));
//		for(int i=0;i<3;i++) cnt[i] = 0;
		cin >> myn;
		for(int i=1;i<=myn;i++) cin >> ma[i].my1 >> ma[i].my2 >> ma[i].my3;
		bool xx1 = fun4();
		if(xx1==true) continue;
		for(int i=1;i<=myn;i++){
			ma[i].mmax = fun3(ma[i].my1,ma[i].my2,ma[i].my3);
			ma[i].mw = fun1(ma[i].my1,ma[i].my2,ma[i].my3,i);
		} 		
		sort(ma+1,ma+myn+1,cmp);
//		for(int i=1;i<=myn;i++){
//			cout <<ma[i].my1<<' '<<ma[i].my2<<' '<<ma[i].my3<<' '<<ma[i].mmax << ' ' << ma[i].mw<<'\n';
//		}	
		for(int i=1;i<=myn;i++){
			aar[i][0] = ma[i].my1;
			aar[i][1] = ma[i].my2;
			aar[i][2] = ma[i].my3;
		}
		for(int i=1;i<=myn;i++){
			if(cnt[ma[i].mw]>=myn/2){
				int dd = fun2(i);
				res+=aar[i][dd];
				cnt[dd]+=1;
			} 
			else {
				cnt[ma[i].mw]+=1;
				res+=ma[i].mmax;
			}
		}
		cout << res << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}// 
