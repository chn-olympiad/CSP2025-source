#include <bits/stdc++.h>
using namespace std;
//======调试======
bool debug = false;
int suojin = 0;
void psj(){for(int i=0;i<suojin;i++)cout << '-';}
//================
struct student{int content1,content2,content3;}a[100005];
int t,n,ans;
void dfs(int numof1,int numof2,int numof3,int sum,int p){
    //numof为目前选择各个社团的人数
    //sum为总的满意度
    //p为已经选择的人数
    //start表示该谁选择了
    if(p==n){
        ans = max(ans,sum);
        if(debug){
            psj();
            cout << "当前方案所有考生已经选完" << endl;
            psj();
            cout << "最大价值为" << ans << endl;
        }
        return;
    }
    
    if(numof1+1<=n/2){
        suojin++;
        dfs(numof1+1,numof2,numof3,sum+a[p].content1,p+1);
        suojin--;
        if(debug){
            psj();
            cout << "正在尝试将让" << p + 1 <<"个考生选择社团1" << a[p].content1<< endl;
            psj();
            cout << "当前总满意度为" << sum << endl;
        }
    }
    if(numof2+1<=n/2){
        suojin++;
        dfs(numof1,numof2+1,numof3,sum+a[p].content2,p+1);
        suojin--;
        if(debug){
            psj();
            cout << "正在尝试将让" << p + 1 <<"个考生选择社团2"<< a[p].content2<< endl;
            psj();
            cout << "当前总满意度为" << sum << endl;
        }
        
    }
    if(numof3+1<=n/2){
        suojin++;
        dfs(numof1,numof2,numof3+1,sum+a[p].content3,p+1);
        suojin--;
        if(debug){
            psj();
            cout << "正在尝试将让" << p + 1 <<"个考生选择社团3"<< a[p].content3<< endl;
            psj();
            cout << "当前总满意度为" << sum << endl;
        }
    }
}//已经调试正确

bool checka(){
    for(int i=0;i<n;i++){
        if(a[i].content2 != 0||a[i].content3 !=0)
            return false;
    }
    return true;
}
bool cmpa(student a,student b){return a.content1 > b.content1;}
bool checkb(){
    for(int i=0;i<n;i++){
        if(a[i].content3 !=0)
            return false;
    }
    return true;
}
bool cmpb(student a,student b){
    int absa = abs(a.content1 - a.content2);
    int absb = abs(b.content1 - b.content2);
    return absa > absb;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i].content1 >> a[i].content2 >> a[i].content3;
        }//不同的数据规模共用输入

        //对于1，2，3，4测试点，数据规模小，直接暴力搜索所有可能的情况即可;
        //时间复杂度为O(3^n)
        //理论得分20
        if(n<=30){
            dfs(0,0,0,0,0);
            cout << ans << endl;
            continue;
        }//已经调试正确

        //对于特殊性质A,所有的考生只对社团1满意
        //所以排序后输出前一半考生的满意度之和就可以了
        //时间复杂度为O(nlogn)
        //理论得分5
        if(checka()){
            sort(a,a+n,cmpa);
            for(int i=0;2*i<n;i++){
                ans += a[i].content1;
                if(debug){
                    cout << "选中" << a[i].content1;
                    cout << "总值为" << ans << endl;
                }
            }
            cout << ans << endl;
            continue;
        }//已经调试正确

        //对于特殊性质B,每个人只对1和2感兴趣
        //为了使得最终的满意最大
        //只根据每个人对1和2的满意度差值排序，排序后对每个人进行分配，当任意一个分配满以后剩下的全部分配到另外一组
        //时间复杂度O(nlogn)
        if(checkb()){
            int cnt1 = 0,cnt2 = 0,idx;
            bool ctn1 = true;
            sort(a,a+n,cmpb);
            for(int i=0;i<n;i++){
                if(2*cnt1==n||2*cnt2==n){
                    if(2*cnt1==n)ctn1 = false;
                    if(2*cnt2==n)ctn1 = true;
                    if(debug){
                        if(ctn1) cout << "2满了"<<endl;
                        if(!ctn1) cout << "1满了" << endl;
                        cout << "当前索引" << idx << endl;
                    }
                    idx = i;
                    break;
                }
                if(debug)cout << "当前索引" << i << endl;
                if(a[i].content1>a[i].content2){
                    cnt1++;
                }else{
                    cnt2++;
                }
                ans += a[i].content1>a[i].content2?a[i].content1:a[i].content2;
                if(debug){
                    cout << "已经把考生分配到" << ((a[i].content1>a[i].content2)?1:2) << endl;
                    cout << "当前价值" << ans << endl;
                }
            }
            for(int i=idx;i<n;i++){
                if(ctn1)
                    ans += a[i].content1;
                if(!ctn1)
                    ans += a[i].content2;
                if(debug){
                    if(ctn1) cout << "固定把"<<i<<"分配到1"<<endl;
                    if(!ctn1) cout << "固定把"<<i<<"分配到2"<< endl;
                    cout << "当前价值" << ans << endl;
                }
            }
            cout << ans << endl;
            continue;
        }
    }
}