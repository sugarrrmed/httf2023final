
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<atcoder/all>
#include<bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
//typedef int ll;

/*
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
namespace multi = boost::multiprecision;
typedef multi::cpp_int LL;
typedef multi::number<multi::cpp_dec_float<1024>> DD;// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
//*/
typedef long double dd;
typedef pair<ll,ll> l_l;
typedef pair<dd,dd> d_d;
ll inf=(ll)1E18;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define rrep(i,r,l) for(ll i=r;i>=l;i--)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
dd EPS=1E-12;
#define fi first
#define se second

#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
template<class T,class S>
inline bool chmax(T &a, S b) {
    if(a < b) {
        a = (T)b;
        return true;
    }
    return false;
}
template<class T,class S>
inline bool chmin(T &a, S b) {
    if(a > b) {
        a = (T)b;
        return true;
    }
    return false;
}
#define all(c) c.begin(),c.end()

//using mint = modint998244353;
//using mint = modint1000000007;
//using mint=modint;
//using mint=static_modint<100>;
//using mint=dd;
//using mint=ll;

typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl>vvvl;
typedef vector<vvvl>vvvvl;
/*
typedef vector<mint>vi;
typedef vector<vi>vvi;
typedef vector<vvi>vvvi;
typedef vector<vvvi>vvvvi;
typedef pair<mint,mint>i_i;
typedef vector<i_i>vi_i;
 //*/
typedef vector<l_l>vl_l;
typedef vector<vl_l>vvl_l;
typedef vector<string>vs;
typedef vector<vs>vvs;
typedef vector<dd> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<d_d>vd_d;
dd PI=acos((dd)-1);

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout<<setprecision(20);
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

//#define endl "\n"  //インタラクティブで消す！！！！！！！！！！！！！！！！！！！！！
#define popcount __builtin_popcountll
#define SHUFFLE(v) shuffle(all(v),default_random_engine(chrono::system_clock::now().time_since_epoch().count()))
//////////////////////////////////////////////////////////////////////////////
template<class S>
void DEBUG_PRINT(S x){
    cerr<<x<<endl;
}
template<class S,class T>
void DEBUG_PRINT(pair<S,T>x){
    cerr<<"("<<x.fi<<","<<x.se<<")"<<endl;
}
template<class S>
void DEBUG_PRINT(vector<S> x){
    for(auto y:x)cerr<<setw(2)<<y<<" ";
    cerr<<endl;
}
template<class S,class T>
void DEBUG_PRINT(vector<pair<S,T>>x){
    for(auto y:x)cerr<<"("<<y.fi<<","<<y.se<<") ";
    cerr<<endl;
}
template<class S>
void DEBUG_PRINT(vector<vector<S>> x){
    cerr<<endl;
    for(auto y:x){
        for(auto z:y){
            cerr<<setw(2)<<z<<" ";
        }cerr<<endl;
    }cerr<<endl;
}

#define TO_STRING_FOR_DEBUG(VariableName) # VariableName
#ifdef LOCAL
#define DEB(V) cerr<< TO_STRING_FOR_DEBUG(V) << ": "; DEBUG_PRINT(V);
#else
#define DEB(V) void(0)
#endif

#define importantBit(x) (63-__builtin_clzll(x))
/////////////////////////////////////////////////////////////////////////////////////////
unsigned int randxor(){
    //0 以上 (2^32)-1 以下の整数(だと思う)
    static unsigned int x=123456789,y=362436069,z=521288629,w=88675123;
    unsigned int t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}
ll rand(ll a,ll b){
    //a以上b以下の整数を返す。
    assert(a<=b);
    ll len=(b-a+1);
    return randxor()%len + a;
}
dd randdouble(dd l,dd r){
    //l以上r以下の実数を返す。
    assert(l<=r + EPS);
    return l + (r-l) * (dd)randxor()/4294967295;
}
struct timespec START_TIME;
dd stop_watch() {
    // 経過時間をミリ秒単位で返す.
    struct timespec end_time;
    clock_gettime(CLOCK_REALTIME, &end_time);
    ll sec = end_time.tv_sec - START_TIME.tv_sec;
    ll nsec = end_time.tv_nsec - START_TIME.tv_nsec;
    return 1000 * (dd)sec + (dd)nsec / (1000000);
}

////////////////////////////////////////////////

ll RHO;
ll R = (ll)1e9;
dd NIL = -10;
ll SUCCESS_CNT = 0;

ll TURN = 0;
bool in_check(l_l P){
    if(abs(P.fi)>R || abs(P.se)>R)return false;
    return P.fi*P.fi + P.se*P.se <= R * R;
}
dd output(l_l P){
    TURN++;
    if(TURN == 1001){
        //cerr<<RHO<<endl;
        DEB(SUCCESS_CNT);
        exit(0);
    }
    ll x=P.fi;
    ll y=P.se;
    
    if(!in_check(P)){
        cerr<<"ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        cerr<<"ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        cerr<<"ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    }
    assert(in_check(P));
    cout<<x<<" "<<y<<endl;
    fflush(stdout);
    ll r;cin>>r;
    if(r==0){
        dd theta;cin>>theta;
        return theta;
    }else{
        SUCCESS_CNT++;
        ll X,Y;cin>>X>>Y;
        if(r==2){
            DEB(SUCCESS_CNT);
            exit(0);
        }
    }
    return NIL;
}
bool nil(dd x){
    return abs(x-NIL)<=1;
}

struct line{
    dd a,b,c;
};
line makeline(l_l p,dd theta){
    //みすってるかも
    dd ta = tan(theta);
  //  DEB(ta);
    return {ta,-1,p.se-ta*p.fi};
}
l_l kouten(line l1,line l2){
    dd a1 = l1.a;
    dd b1 = l1.b;
    dd c1 = l1.c;
    
    dd a2 = l2.a;
    dd b2 = l2.b;
    dd c2 = l2.c;
    
    auto out=[](){
        cerr<<"OUT"<<endl;
        return (l_l){0,0};
    };
    ll x,y;
    {
        dd A =(b1*c2-b2*c1);
        dd B =(a1*b2-a2*b1);
        if(abs(B)<EPS)return out();
        dd C = A/B;
        if(abs(C)>inf)return out();
        x = roundl(C);
    }
    {
        dd A =(a2*c1-a1*c2);
        dd B =(a1*b2-a2*b1);
        if(abs(B)<EPS)return out();
        dd C = A/B;
        if(abs(C)>inf)return out();
        y = roundl(C);
    }
    if(!in_check({x,y}))out();
    
    return {x,y};
}

signed main(){fastio
    clock_gettime(CLOCK_REALTIME, &START_TIME);
    ///////////////////////////////////////
    /*
    rep(i,1,10){
        l_l p;cin>>p.fi>>p.se;
        dd t;cin>>t;
        line l = makeline(p,t);
        cout<<l.a<<" "<<l.b<<" "<<l.c<<endl;
    }exit(0);
    */
    //実験
    ////////////////////////////////////////////////////////////
    
    {
        dd rho;cin>>rho;
        RHO = round(rho * 1000);
    }
    
    
    auto random=[](){
        l_l p = {R,R};
        while(!in_check(p)){
            p.fi = rand(-R,R);
            p.se = rand(-R,R);
        }
        return p;
    };
    
    ll cnt = 0;
    rep(i,1,100000){
        //DEB(i);
        l_l p1 = random();
        l_l p2 = {inf,0};
        for(ll dx=-4e7;dx<=1e7;dx+=1e6){
            for(ll dy=-4e7;dy<=1e7;dy+=1e6){
                if(p2.fi!=inf)continue;
                if(p1==p2)continue;
                p2 = {p1.fi+dx,p1.se+dy};
                if(!in_check(p2))p2={inf,0};
            }
        }
        
        
        
        
        dd theta1 = output(p1);
        if(nil(theta1))continue;
        
        dd theta2 = output(p2);
        if(nil(theta2))continue;
        
        line l1 = makeline(p1,theta1);
        line l2 = makeline(p2,theta2);
        
        l_l kou = kouten(l1,l2);
        if(in_check(kou)){
            output(kou);
            cnt++;
        }
    }
    
    
    
    {
        cerr<<"終了時間は "<<stop_watch()<<"ms"<<endl;
    }
    return 0;
}
