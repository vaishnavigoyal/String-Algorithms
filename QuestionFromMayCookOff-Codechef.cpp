// Question from Codechef : Chef, Chefina and Their Friendship
// Question link : https://www.codechef.com/problems/CHEFSHIP
// Solved using string hashing and sliding window algorithm

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll inv[1000001];   //to store inverse modulo
ll dp[1000001];    //to store hash values from(0,i)

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

  for(ll i=1;i<s.length();i++)
  {
    char ch=s[i];
    p_power=(p_power*p)%mod;
    inv[i]=power(p_power,mod-2);
    dp[i]=(dp[i-1]+(ch-'a'+1)*p_power)%mod;
  }
}

ll substringHash(ll L ,ll R)
{
  ll res=dp[R];
  if(L>0)
  {
    res=(res-dp[L-1]+mod)%mod;
  }
  res=(res*inv[L])%mod;
  return res;
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin>>t;

  while(t--)
  {
    string s;
    cin>>s;

    init(s);

    int cnt=0,n=s.length();
    for(ll i=2;i<n;i+=2)
    {
      ll l1=0,r1=(i/2-1);
      ll l2=(i/2),r2=i-1;
      ll l3=i,r3=(i+n)/2-1;
      ll l4=r3+1,r4=n-1;

      if(substringHash(l1,r1)==substringHash(l2,r2)&&substringHash(l3,r3)==substringHash(l4,r4))
      {
        cnt++;
      }
    }
    cout<<cnt<<endl;
  }
}
