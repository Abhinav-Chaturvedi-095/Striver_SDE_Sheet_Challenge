#include <bits/stdc++.h>
int compareVersions(string v1, string v2) 
{
    int i = 0, j = 0;
        while(i < v1.size() || j < v2.size())
        {
            vector<int> v;
            while(i < v1.size() && v1[i] != '.')
            {
                if(v.size() == 0 && v1[i] != '0') v.push_back(v1[i]);
                else if(v.size() != 0) v.push_back(v1[i]);
                i++;
            }
            i++;
            vector<int> vv;
            while(j < v2.size() && v2[j] != '.')
            {
                if(vv.size() == 0 && v2[j] != '0') vv.push_back(v2[j]);
                else if(vv.size() != 0) vv.push_back(v2[j]);
                j++;
            }
            j++;
            if(v.size() < vv.size()) return -1;
            if(v.size() > vv.size()) return 1;
            for(int i = 0; i < v.size(); i++)
            {
                if(v[i] - '0' < vv[i] - '0') return -1;
                if(v[i] - '0' > vv[i] - '0') return 1;
            }
        }
        return 0;
}


// int compareVersions(string a, string b) 
// {
//     // Write your code here
//     int i = 0; 
//     int j = 0;
//     int n1 = a.size(); 
//     int n2 = b.size();
    
//     int num1 = 0;
//     int num2 = 0;
//     while(i<n1 || j<n2)
//     {
//         while(i<n1 && a[i]!='.'){
//             num1 = num1*10+(a[i]-'0');
//             i++;
//         }
        
//         while(j<n2 && b[j]!='.'){
//             num2 = num2*10+(b[j]-'0');;
//             j++;
//         }
        
//         if(num1>num2) return 1;
//         else if(num1 < num2) return -1;
        
//         num1 = 0;
//         num2 = 0;
//         i++;
//         j++;
//     }
    
//     return 0;
// }
