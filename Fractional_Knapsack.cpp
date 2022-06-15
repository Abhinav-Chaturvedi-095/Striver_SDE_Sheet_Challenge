#include<bits/stdc++.h>
bool cmp(pair<int,int>a,pair<int,int>b ){
   double r1=(double)a.second/(double)a.first;
   double r2=(double)b.second/(double)b.first;
   return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w){
   // Write your code here.
   // ITEMS contains {weight, value} pairs.
   sort(items.begin(),items.end(),cmp);
   int currsum=0;
   double currval=0.0;
   for(int i=0;i<items.size();i++)
   {
       if(currsum+items[i].first<=w){
           currval+=items[i].second;
           currsum+=items[i].first;
       }
       else{
           int rem=w-currsum;
           currval+=((double)rem/(double)items[i].first)*items[i].second;
           break;
       }
   }
   return currval;
}
