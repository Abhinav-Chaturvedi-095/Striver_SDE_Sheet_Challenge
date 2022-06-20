int atoi(string str) {
    // Write your code here.
    long num = 0;
    int i = 0;
    while (str[i]){
        if(str[i] >= '0' && str[i] <= '9')
            num = num * 10 + (str[i] - '0');
        i++;
    }
    if(str[0]=='-')
       num=-1*num;
 
    return num;
}
