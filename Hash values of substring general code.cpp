// General implementation of hash value of substring of a substring
// Constant time approach

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll inv[100001];   //to store inverse modulo
ll dp[100001];    //to store hash values from(0,i)

ll power(ll a,ll n)
{
  ll res=1;
  while(n)
  {
    if(n&1)
    {
      res=(res*a)%mod;
    }
      n>>=1;
      a=(a*a)%mod;
  }
  return res;
}

void init(string s)
{
  ll p=31;
  ll p_power=1;
  inv[0]=1;
  dp[0]=(s[0]-'a'+1);

  for(int i=1;i<s.length();i++)
  {
    char ch=s[i];
    p_power=(p_power*p)%mod;
    inv[i]=power(p_power,mod-2);
    dp[i]=(dp[i-1]+(ch-'a'+1)*p_power)%mod;
  }
}

int substringHash(int L ,int R)
{
  ll res=dp[R];
  if(L>0)
  {
    res-=dp[L-1];
  }
  res=(res*inv[L])%mod;
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin>>s;

  init(s);

  int t,L,R;
  cin>>t;
  while(t--)
  {
    cin>>L>>R;
    cout<<substringHash(L,R)<<endl;
  }
  return 0;
}
