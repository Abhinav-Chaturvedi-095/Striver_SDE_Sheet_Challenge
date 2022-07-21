string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string prefix="";
    if(arr.size()==0)  return prefix;

    // check char by char, for each char, check all the string word 
    for(int k=0; k<arr[0].size(); k++){
        int i=1;
        for(; i<arr.size() && arr[i].size()>k; i++){
            if(arr[i][k]!=arr[0][k])
                return prefix;
        }
        if(i==arr.size()) prefix+=arr[0][k];
    }
    return prefix;

}


