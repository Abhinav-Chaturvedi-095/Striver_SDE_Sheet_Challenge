bool areAnagram(string &str1, string &str2){
    // Write your code here.
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    if(str1==str2) return true;
    return false;
}
