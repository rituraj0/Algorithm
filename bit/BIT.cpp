#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

const ll mod = 1000000007LL;

#define maxn 100009

ll tree[129][maxn];

int in[maxn],col[maxn];

void set_Value( int mask , int id , ll val )
{
     while( id < maxn )
     {
         tree[mask][id]=(tree[mask][id] + val )%mod;;
         id+=( id & (-id));
     }
}

ll get_value( int mask , int id)
{
    ll ans=0;

    while( id > 0)
    {
        ans=(ans + tree[mask][id] )%mod;
        id-=( id & (-id));
    }

    return ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 fill(tree,0);

 int N,K;

 cin>>N>>K;

 for(int i=1;i<=N;i++)
    {cin>>in[i]>>col[i];
     col[i]--;
    }

  int mx=0;

 for(int i=1;i<=N;i++)
 {
     mx=max( mx , in[i] );

     ll newval[130];
     fill(newval,0);

     for(int mask=0;mask<(1<<K);mask++)
     {
         ll tp=get_value(mask, in[i]-1 );
         newval[ mask | (1<<col[i]) ] = ( newval[ mask | (1<<col[i]) ] + tp ) % mod;;
     }

     newval[ (1<<col[i]) ] = ( newval[(1<<col[i]) ] + 1 ) % mod; //only this one

     for(int mask = 0; mask<(1<<K); mask++ )
        set_Value( mask, in[i], newval[mask] );
 }

 cout<<get_value((1<<K)-1,mx);


 return 0;

}
