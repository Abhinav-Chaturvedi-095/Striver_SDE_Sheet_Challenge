int romanToInt(string s) {
    // Write your code here
    int num=0;
    map<char,int> values={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    for(int i=0;i<s.size();i++){
        if(values[s[i]]>=values[s[i+1]])
            num+=values[s[i]];
        else if (values[s[i]]<values[s[i+1]])
            num-=values[s[i]];            
    }
//     if(values[s[0]]>=values[s[1]]) num+=values[s[0]];
//     else num-=values[s[0]];
    return num;
}
